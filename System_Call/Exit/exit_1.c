/*
    --> Program demonstrates normal termination of a process using return from main().
    --> Returning from main() is equivalent to calling exit().
    --> exit(0) indicates successful program termination.
    --> All cleanup operations are performed before process exits.
    --> atexit() registered functions (if any) would be executed.
*/

#include<stdio.h>           // For printf()
#include<stdlib.h>          // For exit()

int main()
{   
    printf("Process is created:\n");   // Display process creation message

    return 0;       // Equivalent to exit(0) – normal successful termination
}
