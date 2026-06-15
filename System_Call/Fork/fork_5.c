/*
    --> Program demonstrates process creation using fork().
    --> fork() creates a child process.
    --> Both parent and child execute the next statement.
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides fork() system call

int main()
{
    fork();                // fork(): creates a new child process

    printf("Jay Ganesh...\n"); // Printed by both parent and child

    return 0;              // Normal program termination
}
