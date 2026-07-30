/*
    --> Program demonstrates file size modification using ftruncate().
    --> open() opens an existing file.
    --> ftruncate() changes the file size.
*/

#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides ftruncate() system call
#include<fcntl.h>          // Provides open() and file access flags

int main()
{
    int iRet = 0;          // Variable to store return value
    int fd = 0;            // File descriptor

    fd = open("Demo.txt", O_RDONLY); // open(): opens file in read-only mode

    iRet = ftruncate(fd, 5);         // ftruncate(): truncate file to 5 bytes

    if(iRet == 0)                     // Check truncate success
    {
        printf("truncate is done:\n");
    }
    else
    {
        printf("there is issue in truncate:\n");
    }

    return 0;                         // Normal program termination
}
