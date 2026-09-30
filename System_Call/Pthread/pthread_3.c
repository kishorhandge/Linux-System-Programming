/****************************************************************************************
* Program Name : Thread Creation using pthread
* Description  : This program demonstrates basic thread creation in C using pthread.
*                A new thread is created which executes a separate function.
*                Both main thread and child thread run concurrently.
*                This example shows how pthread_create() is used.
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <pthread.h>    // For pthread functions

// Thread callback function
void * Demo(void *p)
{
    printf("Inside thread\n");   // Code executed by child thread
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
        printf("Thread gets created successfully\n");
    }

    // Main thread continues execution
    printf("End of main thread\n");

    return 0;          // Return success
}
