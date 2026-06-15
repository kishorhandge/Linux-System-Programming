/*
    --> Program demonstrates parent and child identification using fork().
    --> fork() returns 0 in child process.
    --> fork() returns child PID in parent process.
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides fork() system call

int main()
{
    if(fork() == 0)        // fork(): returns 0 in child process
    {
        printf("Child Process Schedule\n");   // Executed by child
    }
    else
    {
        printf("Parent Process Schedule\n");  // Executed by parent
    }

    return 0;              // Normal program termination
}
