/*
    --> Program demonstrates abnormal process termination using exit().
    --> exit() accepts values in the range 0 to 255.
    --> Exit status 0 indicates successful termination.
    --> Any non-zero exit status indicates failure or error.
    --> Exit status is returned to the parent process (shell).
*/

#include<stdio.h>           // For printf()
#include<stdlib.h>          // For exit()

// 0 to 255        -> Valid exit status range
// 0               -> Success
// Non-zero value  -> Failure

void main()
{   
    printf("Process is created:\n");   // Display process creation message

    exit(11);                          // Terminate process with failure status 11
}
