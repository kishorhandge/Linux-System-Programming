/*
    --> This program demonstrates how to use lseek() to move the file offset.
    --> lseek() allows reading data from a specific position in a file.
    --> The file offset decides from where the read operation starts.
    --> After reading data, the offset automatically moves forward.
    --> lseek() can also be used to get the current position in the file.
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides read(), write(), and lseek()
#include<fcntl.h>          // Provides open() and file access flags
#include<string.h>         // Provides string handling functions
#include<errno.h>          // Provides errno variable
#include<stdlib.h>         // Standard library functions

int main()
{
    int fd = 0;            // File descriptor

    off_t offset = 0;      // Variable to store file offset
    int iRet = 0;          // Variable to store read() return value
    char Buffer[100];      // Buffer to store read data

    fd = open("./LSP.txt", O_RDONLY); // open(): open file in read-only mode

    offset = lseek(fd, 10, SEEK_SET); // lseek(): move offset to 10th byte

    printf("Current offset is : %ld\n", offset); // Print offset (10)

    iRet = read(fd, Buffer, 5);       // read(): read 5 bytes from offset

    printf("\n");

    write(1, Buffer, iRet);            // write(): write data to stdout

    printf("\n");

    offset = lseek(fd, 0, SEEK_CUR);  // lseek(): get current offset

    printf("Current offset is : %ld\n", offset); // Print offset (15)

    return 0;                          // Normal program termination
}
