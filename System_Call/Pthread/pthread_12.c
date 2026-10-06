/****************************************************************************************
* Program Name : Creating Multiple Threads using pthread
* Description  : This program demonstrates how to create more than one thread.
*                Two threads are created, each executing a different function.
*                The main thread waits for both threads to complete execution.
*                pthread_join() is used to synchronize threads.
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <pthread.h>    // For pthread functions

// First thread function
void * Demo(void *p)
{
    printf("Inside Demo thread\n");
    return NULL;
}

// Second thread function
void * Hello(void *p)
{
    printf("Inside Hello thread\n");
    return NULL;
}

int main()
{
    pthread_t TID1, TID2;   // Thread IDs
    int iRet = 0;           // Return value of pthread_create()

    printf("Main thread started\n");

    // Create first thread
    iRet = pthread_create(
                            &TID1,   // Thread ID
                            NULL,   // Default thread attributes
                            Demo,   // Thread callback function
                            NULL    // No parameter
                         );

    if(iRet == 0)
    {
        printf("Thread gets created successfully with TID1 : %lu\n",
               (unsigned long)TID1);
    }

    // Create second thread
    iRet = pthread_create(
                            &TID2,   // Thread ID
                            NULL,   // Default thread attributes
                            Hello,  // Thread callback function
                            NULL    // No parameter
                         );

    if(iRet == 0)
    {
        printf("Thread gets created successfully with TID2 : %lu\n",
               (unsigned long)TID2);
    }

    // Wait for both threads to complete
    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);

    printf("End of main thread\n");

    return 0;           // Return success
}
