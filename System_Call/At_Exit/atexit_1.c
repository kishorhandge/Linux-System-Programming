/*
    --> Program demonstrates the use of atexit() function.
    --> atexit() registers functions to be executed on normal program termination.
    --> Functions registered with atexit() are called in reverse order of registration.
    --> _exit() is used to terminate the process abnormally.
    --> Registered atexit() functions are NOT executed because _exit() bypasses cleanup.
*/

#include<stdio.h>           // For printf()
#include<stdlib.h>          // For atexit()
#include<unistd.h>          // For _exit() system call

void fun()
{
    printf("Inside fun\n"); // Function to be registered with atexit()
}

void gun()
{
    printf("Inside gun\n"); // Function to be registered with atexit()
}

int main()
{   
    printf("Process is created:\n");   // Display process creation message

    atexit(fun);        // Register fun() for normal termination (executed second)
    atexit(gun);        // Register gun() for normal termination (executed first)

    _exit(11);          // Immediate process termination (atexit functions NOT called)
}
