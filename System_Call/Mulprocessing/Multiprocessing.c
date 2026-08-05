/****************************************************************************************
* Program Name : Process Creation using fork and exec (Without wait)
* Description  : This program creates two child processes using fork().
*                Each child process executes a different external program.
*                One child runs the "capital" program and another runs "small".
*                The parent process does not wait for child processes to finish.
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <unistd.h>     // For fork() and execl()

int main()
{
    pid_t pid1 = 0;     // Stores PID returned by first fork()
    pid_t pid2 = 0;     // Stores PID returned by second fork()

    // Create first child process
    pid1 = fork();

    if(pid1 == 0)
    {
        // Child process executes "capital" program
        execl("./capital", "", NULL);
    }
    else
    {
        // Parent process continues execution
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
        // Parent process continues execution
    }

    // Parent process message (may execute before child processes finish)
    printf("End of main process\n");

    return 0;           // Return success
}
