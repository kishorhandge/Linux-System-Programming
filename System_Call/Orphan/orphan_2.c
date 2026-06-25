/*
    --> Program demonstrates parent and child process behavior using fork().
    --> Child process goes into sleep state.
    --> Parent process terminates before child.
*/

#include<stdio.h>          // Provides printf() function
#include<stdlib.h>         // Provides exit() function
#include<unistd.h>         // Provides fork(), getpid(), getppid(), sleep()

int main()
{
    pid_t pid = 0;         // Variable to store fork() return value

    pid = fork();          // fork(): create child process

    if(pid == 0)           // Child process
    {
        printf("Child Process is running....:\n");
        printf("PID of Child is : %d and PPID of Child is %d\n",
                getpid(), getppid());   // Print child and parent IDs

        sleep(20);          // sleep(): put child in sleep state

        printf("PID of Child is : %d and PPID of Child is %d\n",
                getpid(), getppid());   // Print IDs after sleep

        exit(0);            // exit(): terminate child process
    }
    else                   // Parent process
    {
        printf("Parent Process is running....:\n");
        printf("PID of Process is : %d and PPID of Process is %d\n",
                getpid(), getppid());   // Print parent IDs

        exit(1);            // exit(): terminate parent process
    }

    return 0;               // Normal program termination
}
