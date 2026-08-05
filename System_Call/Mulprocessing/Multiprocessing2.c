/****************************************************************************************
* Program Name : Creating Multiple Child Processes using fork and exec
* Description  : This program creates two child processes using fork().
*                Each child process executes a different executable using execl().
*                The parent process waits for both child processes to complete.
*                This demonstrates process creation and synchronization in Linux.
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <unistd.h>     // For fork() and execl()
#include <sys/wait.h>   // For waitpid()

int main()
{
    pid_t pid1 = 0;     // Will store PID of first child process
    pid_t pid2 = 0;     // Will store PID of second child process

    // Create first child process
    pid1 = fork();

    if(pid1 == 0)
    {
        // Child process executes "capital" program
        execl("./capital", "", NULL);
    }
    else
    {
        // Parent process does nothing here
    }

    // Create second child process
    pid2 = fork();

    if(pid2 == 0)
    {
        // Child process executes "small" program
        execl("./small", "", NULL);
    }
    else
    {
        // Parent process does nothing here
    }

    // Parent waits for both child processes to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    // Message printed after both child processes complete
    printf("End of main process\n");

    return 0;           // Return success
}
