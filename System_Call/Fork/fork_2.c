/*
    --> Program demonstrates process creation using fork().
    --> fork() creates a new child process.
    --> fork() returns different values in parent and child.
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides fork(), getpid(), getppid()

int main()
{
    pid_t pid = 0;         // Variable to store return value of fork()

    pid = fork();          // fork(): creates a new process

    printf(
        "PID of current process : %d, "
        "PID of parent : %d, "
        "return value of fork is %d\n",
        getpid(),          // getpid(): returns current process ID
        getppid(),         // getppid(): returns parent process ID
        pid                // fork return value
    );

    return 0;              // Normal program termination
}
