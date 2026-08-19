/*
    --> This program demonstrates parent–child synchronization using waitpid().
    --> Parent process waits until the specific child process terminates.
    --> Child process exits with a custom exit status.
    --> Parent collects child exit information using macros.
    --> Ensures proper child process handling.
*/

#include<stdio.h>          // Provides printf() function
#include<stdlib.h>         // Provides exit() function
#include<unistd.h>         // Provides fork(), getpid(), sleep()
#include<sys/wait.h>       // Provides waitpid() and status macros

int main()
{   
    pid_t childpid = 0;    // Variable to store child PID
    pid_t ret = 0;         // Variable to store waitpid() return value
    int status = 0;        // Variable to store child exit status

    childpid = fork();     // fork(): create child process

    if(childpid == 0)      // Child process
    {
        printf("Child is running with PID : %d\n", getpid());
        sleep(10);         // sleep(): delay execution

        printf("Child process exiting:\n");
        exit(11);          // exit(): terminate child with status 11
    }
    else                   // Parent process
    {
        printf("Parent is running...\n");
        printf("Parent is waiting for child : %d\n", childpid);

        ret = waitpid(childpid, &status, 0); // waitpid(): wait for specific child

        if(WIFEXITED(status))                // Check normal termination
        {
            printf("Child exited with PID : %d\n", ret);
            printf("exit status of child is %d\n", WEXITSTATUS(status));
        }
    }

    return 0;              // Normal program termination
}
