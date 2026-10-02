/****************************************************************************************
* Program Name : Passing Parameter to Thread (Correct Way)
* Description  : This program demonstrates the correct way to pass a parameter
*                from the main thread to a child thread.
*                The address of a variable is passed to the thread function.
*                The thread accesses the value using type casting and dereferencing.
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <pthread.h>    // For pthread functions

// Thread callback function
void * Demo(void *p)
{
    // Access the value passed from main thread
    printf("Inside thread with Value : %d\n", *(int *)p);

    return NULL;        // Terminate thread
}

int main()
{
    pthread_t TID;      // Variable to store thread ID
    int iRet = 0;       // Variable to store return value
    int No = 11;        // Value to be passed to thread

    printf("Main thread started\n");

    // Create thread and pass address of variable
    iRet = pthread_create(
                            &TID,   // Thread ID
                            NULL,   // Default thread attributes
                            Demo,   // Thread callback function
                            &No     // Address passed to thread
                         );

    // Check if thread creation is successful
    if(iRet == 0)
    {
        printf("Thread gets created successfully with TID : %lu\n",
               (unsigned long)TID);
    }

    // Wait for child thread to complete
    pthread_join(TID, NULL);

    printf("End of main thread\n");

    return 0;           // Return success
}
