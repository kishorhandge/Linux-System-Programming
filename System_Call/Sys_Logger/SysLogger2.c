//argc =1
//  argv[0]     argv[1]      argv[2]
//  ./myexe 

// argc = 2
//  argv[0]     argv[1]      
//  ./myexe    /home/demo


//  argc = 3
//  argv[0]     argv[1]      argv[2]
//  ./myexe    /home/demo    5

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
    double cp;   //cpu usage percentage
    double mem;  //ram usage percentage
    double disk; //hard disk usage percentage


}Snapshot;


//Global object which hold infomation
static Snapshot snap;

//Mutex lock for critical section
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;


//Default path for disk
static const char * disk_path = "/";

//Sleep timer for log
static int interval_sec = 2;

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

    while(1)
    {
        sleep(1);
    }

    return 0;
}