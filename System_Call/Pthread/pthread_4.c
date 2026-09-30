/****************************************************************************************
* Program Name : Thread Creation and Synchronization using pthread
* Description  : This program demonstrates how to create a thread using pthread.
*                The main thread waits for the child thread to complete execution.
*                pthread_join() is used for synchronization between threads.
*                This ensures proper execution order in multithreaded programs.
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <pthread.h>    // For pthread functions

// Thread callback function
void * Demo(void *p)
{
    printf("Inside thread\n");   // Executed by child thread
    return NULL;
}

int main()
{
    pthread_t TID;     // Variable to store thread ID
    int iRet = 0;      // Variable to store return value

    printf("Main thread started\n");

    // Create a new thread
    iRet = pthread_create(
                            &TID,   // Thread ID
                            NULL,   // Default thread attributes
                            Demo,   // Thread callback function
                            NULL    // Parameter to callback function
                         );

    // Check if thread creation is successful
    if(iRet == 0)
    {
        printf("Thread gets created successfully with TID : %lu\n",
               (unsigned long)TID);
    }

    // Wait for the child thread to finish execution
    pthread_join(TID, NULL);

    printf("End of main thread\n");

    return 0;          // Return success
}
