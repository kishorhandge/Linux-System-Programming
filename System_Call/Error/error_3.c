/*
    -->Program tries to open Marvellous.txt file if it open succesfully,

    --> then print its fd otherwise print error number.

    --> Also print human readable error message

*/

include<stdio.h>
#include<errno.h>       //used to get error numbers when a system call fails.
#include<fcntl.h>       //used for file opening and file control operations.
#include<string.h>      //used for string-related functions like strcpy, strlen, strerror.


int main()
{   
    int fd = 0;
    fd = open("Marvellous.txt",O_RDONLY);               //used to open file using OPEN() system call

    printf("Value of fd is %d\n",fd);

    printf("Value of errno is : %d\n",errno);

    printf("error statement : %s\n",strerror(errno));   //used to print human readable message
    
    return 0;
}