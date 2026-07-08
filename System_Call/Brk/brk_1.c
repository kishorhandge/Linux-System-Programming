/*
    --> Program demonstrates termination of a process using _exit().
    --> Prints a message when the process is created.
    --> _exit() immediately terminates the process.
    --> Exit status 11 is returned to the parent process.
    --> No cleanup functions or stdio buffers are flushed.
*/

#include<stdio.h>          // Provides printf() function
#include<stdlib.h>         // Standard library functions
#include<unistd.h>         // Provides _exit() system call

int main()
{
    printf("Process is created:\n");   // Print process creation message

    _exit(11);                         // _exit(): immediately terminates the process with status 11
}
