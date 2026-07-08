/*
    --> Program demonstrates memory allocation and deallocation using brk().
    --> sbrk(0) is used to get the current program break.
    --> brk() increases the program break to allocate memory.
    --> Data is stored in the newly allocated memory.
    --> brk() is used again to restore the break (free memory).
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides brk() and sbrk() system calls
#include<string.h>         // Provides strcpy() function

int main()
{
    void *current_break = NULL;                          // Pointer to store current program break

    current_break = sbrk(0);                             // sbrk(0): get current program break

    printf("Current process break %p\n", current_break); // Print current break address

    brk((char *)current_break + 100);                     // brk(): increase break by 100 bytes

    strcpy((char *)current_break, "Jay Ganesh...");        // Copy data to allocated memory

    printf("data from new memory %s\n", (char *)current_break); // Print stored data

    brk(current_break);                                     // brk(): restore original break (free memory)

    return 0;                       
}