/*
    This program tries to print the current working directory.
    But this code gives an ERROR because getcwd() is used wrongly.
*/

#include<stdio.h>     // For printf()
#include<string.h>
#include<errno.h>     // For errno
#include<unistd.h>    // For getcwd()

int main()
{   
     

    printf("Current directory name: %s\n", getcwd()); // ERROR

    return 0;
}
