/*
    --> Program demonstrates duplication of a file descriptor using dup2().
    --> open() opens a file and returns a file descriptor.
    --> dup2() duplicates fd1 into a specified file descriptor.
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides dup2() and close() system calls
#include<fcntl.h>          // Provides open() and file access flags
#include<string.h>         // Provides string handling functions
#include<stdlib.h>         // Standard library functions

int main()
{
    int fd1 = 0;                    // File descriptor for original file
    int fd2 = 0;                    // File descriptor for duplicated file

    fd1 = open("./LSP.txt", O_RDWR); // open(): opens file in read-write mode

    printf("fd1: %d\n", fd1);        // Print original file descriptor

    fd2 = dup2(fd1, 13);             // dup2(): duplicate fd1 into fd number 13

    printf("fd2: %d\n", fd2);        // Print duplicated file descriptor

    return 0;                        // Normal program termination
}
