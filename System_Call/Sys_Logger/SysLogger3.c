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


//////////////////////////////////////////////////////////////////////////////
//
//                  Helper functions definations
//
//
//////////////////////////////////////////////////////////////////////////////


//thread proc for thread which collect system information
static void * collector_thread(void * arg)
{   
    (void)arg;
    printf("Inside collector thread\n");

    return NULL;
}

//thread proc for thread which write log
static void * logger_thread(void * arg)
{    
    (void)arg;
    printf("Inside logger thread\n");

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