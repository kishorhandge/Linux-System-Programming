/*
    This program prints the PID (Process ID) of the current process.

    1) getpid() returns the unique ID of the program running now.
    2) We use printf() to display it on the screen.
*/

#include<stdio.h>                       // For printf
#include<unistd.h>                      // For getpid() system call

int main()
{
    printf("PID of current process is: %d\n", getpid());  // Print the current process ID
    
    return 0;    
}
