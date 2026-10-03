/****************************************************************************************
* Program Name : Returning Value from Thread using pthread
* Description  : This program demonstrates how a thread can compute a result
*                and return it to the main thread.
*                An array is passed to the thread, and its elements are summed.
*                The main thread receives the result using pthread_join().
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <pthread.h>    // For pthread functions

// Thread callback function
void * Demo(void *p)
{   
    int iSum = 0;

    printf("Inside thread\n");

    // Calculate sum of array elements using pointer arithmetic
    iSum = (*((int *)p + 0)) +
           (*((int *)p + 1)) +
           (*((int *)p + 2)) +
           (*((int *)p + 3));

    // Exit thread and return the result
    pthread_exit((int *)iSum);
}

int main()
{   
    pthread_t TID;      // Variable to store thread ID
    int iRet = 0;       // Return value of pthread_create()
    int Value = 0;      // Variable to store result from thread
    int Arr[] = {11, 21, 51, 101};  // Input array

    printf("Main thread started\n");

    // Create thread and pass array base address
    iRet = pthread_create(
                            &TID,       // Thread ID
                            NULL,       // Default thread attributes
                            Demo,       // Thread callback function
                            (int *)Arr  // Parameter to thread
                         );

    // Check if thread creation is successful
    if(iRet == 0)
    {
        printf("Thread gets created successfully with TID : %lu\n",
               (unsigned long)TID);
    }

    // Wait for child thread and collect returned value
    pthread_join(TID, (void *)&Value);

    // Print result received from thread
    printf("Summation is : %d\n", Value);

    printf("End of main thread\n");

    return 0;           // Return success
}
