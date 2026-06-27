/*
    --> This program demonstrates reading data using pread().
    --> pread() reads data from a specific offset in a file.
    --> File offset is not changed after pread() call.
    --> It avoids using lseek() before read().
    --> Useful for thread-safe file reading.
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides pread(), write(), and lseek()
#include<fcntl.h>          // Provides open() and file access flags
#include<string.h>         // Provides string handling functions
#include<errno.h>          // Provides errno variable
#include<stdlib.h>         // Standard library functions

int main()
{
    int fd = 0;            // File descriptor

    off_t offset = 0;      // Variable to store file offset
    int iRet = 0;          // Variable to store pread() return value
    char Buffer[100];      // Buffer to store read data

    fd = open("./LSP.txt", O_RDONLY); // open(): open file in read-only mode

    iRet = pread(fd, Buffer, 5, 10);  // pread(): read 5 bytes from offset 10
    
    printf("\n");
    
    write(1, Buffer, iRet);           // write(): write data to stdout

    printf("\n");

    offset = lseek(fd, 0, SEEK_CUR);  // lseek(): get current offset

    printf("Current offset is : %ld\n", offset); // Offset remains unchanged

    return 0;                          // Normal program termination
}
