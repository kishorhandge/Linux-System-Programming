/*
    --> Program demonstrates changing process priority using nice().
    --> nice() increases the nice value of the process.
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides nice() system call

int main()
{
    int ret = 0;           // Variable to store nice value

    ret = nice(0);         // nice(0): get current nice value

    printf("Current nice value : %d\n", ret); // Print initial nice value
    
    ret = nice(5);         // nice(5): increase nice value (decrease priority)

    printf("Current nice value : %d\n", ret); // Print updated nice value

    return 0;              // Normal program termination
}
