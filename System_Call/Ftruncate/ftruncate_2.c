/*
    --> Program demonstrates the use of ftruncate() system call in Linux.
    --> Opens "Demo.txt" in read-write mode (O_RDWR).
    --> ftruncate() changes the size of the file to 5 bytes.
    --> If the file size is larger than 5 bytes, extra data is removed.
    --> If the file size is smaller than 5 bytes, it is extended with null bytes.
*/

#include<stdio.h>           // For printf()
#include<unistd.h>          // For ftruncate()
#include<fcntl.h>           // For open() and O_RDWR

int main()
{
    int iRet = 0;           // To store return value of ftruncate()
    int fd = 0;             // File descriptor

    fd = open("Demo.txt", O_RDWR);   // Open file in read-write mode

    iRet = ftruncate(fd, 5);         // Truncate or extend file to 5 bytes

    if(iRet == 0)                     // Check if truncate is successful
    {
        printf("truncate is done:\n");
    }
    else
    {
        printf("there is issue in truncate:\n");
    }

    return 0;
}
