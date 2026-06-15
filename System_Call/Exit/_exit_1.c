/*
    --> Program demonstrates termination of a process using _exit().
    --> The program prints a message indicating process creation.
    --> _exit() immediately terminates the process with a status code.
    --> Exit status 11 is returned to the parent process.
    --> No cleanup functions or stdio buffers are flushed.
*/

#include<stdio.h>           // For printf()
#include<stdlib.h>          // Standard library functions
#include<unistd.h>          // For _exit() system call

int main()
{   
    printf("Process is created:\n");   // Display message on terminal

    _exit(11);                         // Immediately terminate process with exit status 11
}
