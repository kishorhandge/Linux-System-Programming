/*
    --> Program demonstrates process creation using fork().
    --> fork() creates a new child process.
    --> Child process gets return value 0 from fork().
    --> Parent process gets child PID from fork().
    --> sleep() is used to delay child execution.
*/

#include<stdio.h>           // For printf()
#include<stdlib.h>          // Standard library functions
#include<sys/wait.h>        // For wait-related system calls
#include<unistd.h>          // For fork() and sleep()

int main()
{
    pid_t pid = 0;          // Variable to store process ID

    pid = fork();           // Create a new process

    if(pid == 0)            // Child process condition
    {
        sleep(10);          // Delay child process execution for 10 seconds
        printf("child process is running\n");   // Child process message
    }
    else                    // Parent process condition
    {
        printf("parent process is running\n");  // Parent process message
    }

    return 0;               // Normal termination
}
