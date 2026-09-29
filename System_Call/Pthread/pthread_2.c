/****************************************************************************************
* Program Name : Array Modification using Pointer
* Description  : This program demonstrates how an array is passed to a function.
*                The function receives the base address of the array.
*                Using pointer arithmetic, array elements are modified.
*                Changes made inside the function reflect in the main function.
****************************************************************************************/

#include <stdio.h>     // For printf()

// Function to modify array elements using pointer
void Demo(int *p)
{
    *p = 11;           // Assign value to first element (p[0])
    *(p + 1) = 21;     // Assign value to second element (p[1])
}

int main()
{
    int Arr[2];        // Array of size 2

    // Pass array name (base address) to function
    Demo(Arr);

    // Print modified array values
    printf("Return value is : %d %d\n", Arr[0], Arr[1]);

    return 0;          // Return success
}
