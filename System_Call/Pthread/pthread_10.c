/****************************************************************************************
* Program Name : Returning Value from Thread using malloc
* Description  : This program demonstrates how a thread can return a value safely.
*                The thread calculates the sum of array elements.
*                Memory is allocated dynamically inside the thread.
*                The main thread receives and uses the returned result.
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <pthread.h>    // For pthread functions
#include <stdlib.h>     // For malloc()

// Thread callback function
void * Demo(void *p)
{   
    int iSum = 0;
    int *ptr = NULL;

    // Allocate memory to store result
    ptr = (int *)malloc(sizeof(int));

    printf("Inside thread\n");

    // Calculate sum of array elements
    iSum = (*((int *)p + 0)) +
           (*((int *)p + 1)) +
           (*((int *)p + 2)) +
           (*((int *)p + 3));

    // Store result in allocated memory
    *ptr = iSum;

    // Exit thread and return pointer to result
    pthread_exit(ptr);
}

int main()
{   
    pthread_t TID;          // Thread ID
    int iRet = 0;           // Return value of pthread_create()
    int *Value = NULL;      // Pointer to receive result from thread
    int Arr[] = {11, 21, 51, 101};  // Input array

    printf("Main thread started\n");

    // Create child thread
    iRet = pthread_create(
                            &TID,       // Thread ID
                            NULL,       // Default attributes
                            Demo,       // Thread function
                            (int *)Arr  // Parameter to thread
                         );

    // Check thread creation status
    if(iRet == 0)
    {
        printf("Thread gets created successfully with TID : %lu\n",
               (unsigned long)TID);
    }

    // Wait for child thread and get returned value
    pthread_join(TID, (void **)&Value);

    // Print the result
    printf("Summation is : %d\n", *Value);

    // Free allocated memory
    free(Value);

    printf("End of main thread\n");

    return 0;               // Return success
}
