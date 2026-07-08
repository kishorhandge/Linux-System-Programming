/*
    --> Program demonstrates dynamic memory allocation using brk() and sbrk().
    --> sbrk(0) gets the current program break.
    --> brk() increases the program break to allocate memory.
    --> Data is written into newly allocated memory.
    --> sbrk(-100) releases the allocated memory.
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides brk() and sbrk() system calls
#include<string.h>         // Provides strcpy() function

int main()
{
    void *current_break = NULL;    // Pointer to store current program break

    current_break = sbrk(0);       // sbrk(0): get current program break

    printf("Current process break %p\n", current_break); // Print current break address

    brk((char *)current_break + 100);  // brk(): increase break by 100 bytes

    strcpy((char *)current_break, "Jay Ganesh..."); // Copy data to newly allocated memory

    printf("data from new memory %s\n", (char *)current_break); // Print stored data

    sbrk(-100);    // sbrk(-100): decrease break to free memory

    return 0;       
}
