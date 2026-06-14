/*
    --> Program demonstrates duplication of a file descriptor using dup().
    --> open() opens a file and returns a file descriptor.
    --> dup() creates a duplicate file descriptor for the same file.
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides dup() and close() system calls
#include<fcntl.h>          // Provides open() and file access flags
#include<string.h>         // Provides string handling functions
#include<stdlib.h>         // Standard library functions

int main()
{
    int fd1 = 0;           // File descriptor for original file
    int fd2 = 0;           // File descriptor for duplicated file

    fd1 = open("./LSP.txt", O_RDWR); // open(): opens file in read-write mode

    printf("fd1: %d\n", fd1);        // Print original file descriptor

    fd2 = dup(fd1);                  // dup(): duplicate fd1 into a new fd

    printf("fd2: %d\n", fd2);        // Print duplicated file descriptor

    return 0;                      
