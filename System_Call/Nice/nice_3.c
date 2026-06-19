/*
    --> Program demonstrates priority increase using nice().
    --> nice() may fail when increasing priority.
    --> errno stores the error reason.
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides nice() system call
#include<errno.h>          // Provides errno variable
#include<string.h>         // Provides strerror() function

int main()
{
    int ret = 0;           // Variable to store nice value

    ret = nice(0);         // nice(0): get current nice value

    printf("Current nice value : %d\n", ret); // Print initial nice value
    
    ret = nice(-5);        // nice(-5): try to increase priority

    if(ret == -1)          // Check for error
    {
        printf("%s\n", strerror(errno)); // Print error message
    }

    printf("Current nice value : %d\n", ret); // Print nice value

    return 0;              // Normal program termination
}
