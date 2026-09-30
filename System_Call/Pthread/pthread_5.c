/****************************************************************************************
* Program Name : Thread Termination using pthread_exit()
* Description  : This program demonstrates thread creation and proper thread termination.
*                The child thread terminates itself using pthread_exit().
*                The main thread waits for the child thread using pthread_join().
*                Finally, the main thread also exits using pthread_exit().
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <pthread.h>    // For pthread functions

// Thread callback function
void * Demo(void *p)
{
    printf("Inside thread\n");

    // Terminate the child thread explicitly
    pthread_exit(NULL);

    return NULL;    // Not reached
}

int main()
{
    pthread_t TID;     // Variable to store thread ID
    int iRet = 0;      // Variable to store return value

    printf("Main thread started\n");

    // Create a new child thread
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

    // Wait for the child thread to complete
    pthread_join(TID, NULL);

    // Terminate the main thread
    pthread_exit(NULL);

    printf("End of main thread\n"); // This line will not execute

    return 0;   // Not reached
}
