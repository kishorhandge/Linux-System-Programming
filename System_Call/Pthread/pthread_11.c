/****************************************************************************************
* Program Name : Multiple Thread Creation using pthread
* Description  : This program demonstrates how to create multiple threads in C.
*                Two separate threads execute different functions.
*                The main thread waits for both threads to complete.
*                pthread_join() is used for proper synchronization.
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <pthread.h>    // For pthread functions

// First thread callback function
void * Demo(void *p)
{
    printf("Inside Demo thread\n");
    return NULL;
}

// Second thread callback function
void * Hello(void *p)
{
    printf("Inside Hello thread\n");
    return NULL;
}

int main()
{
    pthread_t TID1, TID2;   // Thread IDs for two threads
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
