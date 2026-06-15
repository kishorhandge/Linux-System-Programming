/*
    --> Program demonstrates process termination using exit() with void main().
    --> exit() is explicitly used to terminate the process.
    --> exit(0) indicates successful normal termination.
    --> All cleanup operations are performed before exiting.
    --> Though commonly used, void main() is NOT standard in C.
*/

#include<stdio.h>           // For printf()
#include<stdlib.h>          // For exit()

void main()
{   
    printf("Process is created:\n");   // Display process creation message

    exit(0);                            // Normal termination with success status
}
