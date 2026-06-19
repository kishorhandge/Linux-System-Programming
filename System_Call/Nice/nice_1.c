/*
    --> Program demonstrates process priority retrieval using nice().
    --> nice() returns the current nice value of the process.
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides nice() system call

int main()
{
    int ret = 0;           // Variable to store nice value

    ret = nice(0);         // nice(0): get current process nice value

    printf("Current nice value : %d\n", ret); // Print nice value
    
    return 0;              // Normal program termination
}
