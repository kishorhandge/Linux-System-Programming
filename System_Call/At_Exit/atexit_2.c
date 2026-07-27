/*
    --> Program demonstrates normal process termination using exit().
    --> atexit() is used to register cleanup functions.
    --> Registered functions are executed in reverse order of registration.
    --> exit() performs proper cleanup before terminating the process.
    --> atexit() functions ARE executed when exit() is called.
*/

#include<stdio.h>           // For printf()
#include<stdlib.h>          // For exit() and atexit()
#include<unistd.h>          // For POSIX functions

void fun()
{
    printf("Inside fun\n"); // Function registered with atexit()
    // exit(11);            // Interview question: causes recursive termination call
}

void gun()
{
    printf("Inside gun\n"); // Function registered with atexit()
}

int main()
{   
    printf("Process is created:\n");   // Display process creation message

    atexit(fun);        // Register fun() (executed second)
    atexit(gun);        // Register gun() (executed first)

    exit(11);           // Normal process termination with cleanup
}
