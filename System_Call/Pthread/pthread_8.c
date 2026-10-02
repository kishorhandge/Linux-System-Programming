/****************************************************************************************
* Program Name : Passing Array to Thread using pthread
* Description  : This program demonstrates how to pass an array to a thread.
*                The base address of the array is passed to the thread function.
*                Pointer arithmetic is used to access array elements.
*                The child thread prints all elements of the array.
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <pthread.h>    // For pthread functions

// Thread callback function
void * Demo(void *p)
{
    printf("Inside thread with values:\n");

    // Access array elements using pointer arithmetic
    printf("%d\n", *((int *)p + 0));   // p[0]
    printf("%d\n", *((int *)p + 1));   // p[1]
    printf("%d\n", *((int *)p + 2));   // p[2]
    printf("%d\n", *((int *)p + 3));   // p[3]

    return NULL;        // Terminate thread
}

int main()
{
    pthread_t TID;      // Variable to store thread ID
    int iRet = 0;       // Variable to store return value
    int Arr[] = {11, 21, 51, 101};  // Array to pass to thread

    printf("Main thread started\n");

    // Create thread and pass base address of array
    iRet = pthread_create(
                            &TID,       // Thread ID
                            NULL,       // Default thread attributes
                            Demo,       // Thread callback function
                            (int *)Arr  // Base address of array
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
