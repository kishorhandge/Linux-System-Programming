/*
    --> Program demonstrates file offset manipulation using lseek().
    --> lseek() is used to get and change file read position.
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides read() and lseek()
#include<fcntl.h>          // Provides open() and file access flags
#include<string.h>         // Provides string handling functions
#include<errno.h>          // Provides errno variable
#include<stdlib.h>         // Standard library functions

int main()
{
    int fd = 0;            // File descriptor

    off_t offset = 0;      // Variable to store file offset
    char Buffer[100];      // Buffer to read file data

    fd = open("./LSP.txt", O_RDONLY); // open(): open file in read-only mode

    offset = lseek(fd, 0, SEEK_SET);  // lseek(): set offset to beginning

    printf("Current offset is : %ld\n", offset); // Print offset (0)

    read(fd, Buffer, 10);              // read(): read 10 bytes from file

    offset = lseek(fd, 0, SEEK_CUR);  // lseek(): get current offset

    printf("Current offset is : %ld\n", offset); // Print offset (10)

    return 0;                          // Normal program termination
}
