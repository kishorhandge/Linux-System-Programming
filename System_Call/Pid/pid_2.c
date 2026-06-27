
/*
    This program prints the PID (Process ID) of the current process
    and the PID of its parent process.

    1) getpid() returns the unique ID of the current process.
    2) getppid() returns the PID of the parent process.
    3) On Linux shell, you can see your shell's PID using: echo $$
*/

#include<stdio.h>                                           // For printf
#include<unistd.h>                                          // For getpid() and getppid() system calls

int main()
{
    printf("PID of current process is: %d\n", getpid());    // Print current process ID
    printf("PID of parent process is: %d\n", getppid());    // Print parent process ID
    
    return 0;   
}

//scrpting language to display use : echo $$