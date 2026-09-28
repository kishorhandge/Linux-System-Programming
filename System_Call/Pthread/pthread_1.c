/****************************************************************************************
* Program Name : Call by Address (Pointer Example)
* Description  : This program demonstrates call by address using pointers in C.
*                A variable is passed to a function using its address.
*                The function modifies the original value using a pointer.
*                Changes made inside the function reflect in the main function.
****************************************************************************************/

#include <stdio.h>     // For printf()

// Function that modifies the value using pointer
void Demo(int *p)
{
    *p = 11;           // Change the value at the given address
}

int main()
{
    int no = 0;        // Local variable initialized to 0

    // Pass address of variable to the function
    Demo(&no);

    // Print modified value
    printf("Return value is : %d\n", no);

    return 0;          // Return success
}
