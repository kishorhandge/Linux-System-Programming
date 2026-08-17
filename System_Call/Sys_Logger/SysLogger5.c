//argc =1
//  argv[0]     argv[1]      argv[2]
//  ./myexe 

// argc = 2
//  argv[0]     argv[1]      
//  ./myexe    /home/demo


//  argc = 3
//  argv[0]     argv[1]      argv[2]
//  ./myexe    /home/demo    5

//////////////////////////////////////////////////////////////////////////////
//
//                Header file Inclusion
//
//
//////////////////////////////////////////////////////////////////////////////

#define _GNU_SOURCE

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<signal.h>
#include<fcntl.h>
#include<time.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/statvfs.h>


//////////////////////////////////////////////////////////////////////////////
//
//                 Global variable creation
//
//
//////////////////////////////////////////////////////////////////////////////

static volatile sig_atomic_t stop_flag = 0;

//ctrl + c handler
static void sigint_handler(int sig)
{   

    (void)sig;  //important

    printf("Marvellous System Logger is Terminating\n");

    //tell the threads to stop the execution
    stop_flag = 1;
}

//structure which holds all system infomation
typedef struct 
{
    double cpu;   //cpu usage percentage
    double mem;  //ram usage percentage
    double disk; //hard disk usage percentage


}Snapshot;


//Global object which hold infomation
static Snapshot snap;

//Mutex lock for critical section
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;


//Default path for disk
static char * disk_path = "/";

//Sleep timer for log
static int interval_sec = 2;


//////////////////////////////////////////////////////////////////////////////
//
//                  Helper functions definations
//
//
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//  function to collect cpu information
//////////////////////////////////////////////////////////////////////////////

static void timestamp(char *out, size_t sz)
{
    time_t now = time(NULL);
    struct tm t;

    localtime_r(&now, &t);
    strftime(out, sz, "%Y-%m-%d %H:%M:%S", &t);
}

///////////////////////////////////////////////////////////////
// CPU helpers (/proc/stat)
// CPU% = (delta_total - delta_idle) / delta_total * 100
///////////////////////////////////////////////////////////////

static int read_cpu(unsigned long long *total, unsigned long long *idle_all)
{
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) return -1;

    char line[512];

    if (!fgets(line, sizeof(line), fp))
    {
        fclose(fp);
        return -1;
    }

    fclose(fp);

    unsigned long long user = 0, nice = 0, sys = 0, idle = 0;
    unsigned long long iowait = 0, irq = 0, softirq = 0, steal = 0;

    int n = sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu",
                   &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal);

    if (n < 4) return -1;

    *idle_all = idle + iowait;

    *total = user + nice + sys + idle + iowait + irq + softirq + steal;

    return 0;
}

static double cpu_percent()
{   
    //logic to ftech cpu information   

    unsigned long long t1 = 0, i1 = 0, t2 = 0, i2 = 0;

    if (read_cpu(&t1, &i1) != 0) return 0.0;

    // measure CPU delta over 1 second
    for (int i = 0; i < 1 && !stop_flag; i++) sleep(1);

    if (stop_flag) return 0.0;

    if (read_cpu(&t2, &i2) != 0) return 0.0;

    unsigned long long dt = t2 - t1;
    unsigned long long di = i2 - i1;

    if (dt == 0) return 0.0;

    return ((double)(dt - di) / (double)dt) * 100.0; 
    
}


//////////////////////////////////////////////////////////////////////////////
//  function to fetch memory information
//////////////////////////////////////////////////////////////////////////////


static double mem_percent()
{       
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) return 0.0;

    unsigned long long total = 0, avail = 0;
    char key[64], unit[32];
    unsigned long long val = 0;

    while (fscanf(fp, "%63s %llu %31s", key, &val, unit) == 3)
    {
        if (strcmp(key, "MemTotal:") == 0) total = val;
        else if (strcmp(key, "MemAvailable:") == 0) avail = val;

        if (total && avail) break;
    }

    fclose(fp);

    if (total == 0) return 0.0;

    return ((double)(total - avail) / (double)total) * 100.0;
}


//////////////////////////////////////////////////////////////////////////////
//  function to fetch disk information
//////////////////////////////////////////////////////////////////////////////


static double disk_percent(char *path)
{   
    //logic to ftech disk information
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) return 0.0;

    unsigned long long total = 0, avail = 0;
    char key[64], unit[32];
    unsigned long long val = 0;

    while (fscanf(fp, "%63s %llu %31s", key, &val, unit) == 3)
    {
        if (strcmp(key, "MemTotal:") == 0) total = val;
        else if (strcmp(key, "MemAvailable:") == 0) avail = val;

        if (total && avail) break;
    }

    fclose(fp);

    if (total == 0) return 0.0;

    return ((double)(total - avail) / (double)total) * 100.0;
}

//thread proc for thread which collect system information
static void * collector_thread(void * arg)
{      
    double c = 0.0 , m = 0.0 , d = 0.0;

    (void)arg;
    printf("Inside collector thread\n");

    //Enter if ctrl + c is not arrived
    while(!stop_flag)
    {   
        c = cpu_percent();
        if (stop_flag) break;

        m = mem_percent();
        d = disk_percent(disk_path);

        pthread_mutex_lock(&mtx);

        double c = cpu_percent();
        double m = mem_percent();
        double d = disk_percent(disk_path);


        //start the critical section
        pthread_mutex_lock(&mtx);
        snap.cpu = c;
        snap.mem = m;
        snap.disk = d;

        //end the critical section
        pthread_mutex_unlock(&mtx);
    }

    return NULL;

}

//thread proc for thread which write log
static void * logger_thread(void * arg)
{    
    double m = 0.0 , d = 0.0 , c = 0.0;
    int fd = 0;
    int i = 0;

    (void)arg;
    printf("Inside logger thread\n");


    fd = open("Marvellous_log.txt",O_CREAT | O_WRONLY | O_APPEND , 0666);

    char welcome[] = "Marvellous system logger";

    write(fd,welcome,strlen(welcome));

    //Enter if ctrl + c is not arrived
    while(!stop_flag)
    {   
        pthread_mutex_lock(&mtx);

        d = snap.disk;
        c = snap.cpu;
        m = snap.mem;


        pthread_mutex_unlock(&mtx);

        
        //prepare string using sprintf write that string into log file

        char line[256];

        //write the infomation of structure (snap) into the file

        write(fd,line,strlen(line));


        //sleep for interval

        for(i = 0;i<interval_sec && !stop_flag;i++)
        {
            sleep(1);
        }
    }

    close(fd);
    return NULL;
}


//////////////////////////////////////////////////////////////////////////////
//
//                  Entry point function of project
//
//
//////////////////////////////////////////////////////////////////////////////

int main(int argc , char * argv[])
{   

    //  ./myexe    /home/demo
    if(argc == 2)
    {
        disk_path = argv[1];
    }
    //  ./myexe    /home/demo    5
    else if(argc == 3)
    {
        disk_path = argv[1];
        interval_sec = atoi(argv[2]);

    }
    printf("Marvellous System Logger\n");


    printf("Path is : %s\n",disk_path);
    printf("interval  is %d\n",interval_sec);

    //structure for handling ctrl + c
    struct sigaction sa;
    memset(&sa,0,sizeof(sa));

    sa.sa_handler = sigint_handler;

    sigaction(SIGINT,&sa,NULL);


    //Thread to collect the information
    pthread_t t_collect;

    //Thread to write data into log
    pthread_t t_log;


    // collect thread to collect information
    pthread_create(&t_collect,NULL,collector_thread,NULL);

    //write data into log
    pthread_create(&t_log,NULL,logger_thread,NULL);


    //main waiting for child threads to terminate
    pthread_join(t_collect, NULL);
    pthread_join(t_log,NULL);

    printf("Terminating the marvellous system log\n");



    return 0;
}