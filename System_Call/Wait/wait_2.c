/*
    --> Program demonstrates parent-child synchronization using fork() and wait().
    --> Parent process waits for child process to terminate.
    --> Child process sleeps for some time and exits with a specific status.
    --> wait() returns the PID of the terminated child.
    --> WEXITSTATUS() extracts the exit code of the child process.
*/

#include<stdio.h>           // For printf()
#include<stdlib.h>          // For exit()
#include<sys/wait.h>        // For wait() and macros like WEXITSTATUS()
#include<unistd.h>          // For fork() and sleep()


int main()
{
    pid_t pid = 0;          // Variable to store fork() return value
    pid_t x = 0;            // Variable to store terminated child PID

    int status = 0;         // Variable to store child exit status

    pid = fork();           // Create child process

    if(pid == 0)            // Child process
    {
        sleep(10);          // Delay child execution
        exit(21);           // Child exits with status 21
    }

    x = wait(&status);      // Parent waits for child to terminate
    
    printf("Child with PID %d gets terminated with status %d\n",
            x, WEXITSTATUS(status));   // Display child PID and exit status

    return 0;               // Normal termination of parent
}
