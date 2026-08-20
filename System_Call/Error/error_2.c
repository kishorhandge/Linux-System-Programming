/*
    -->Program tries to open Marvellous.txt file if it open succesfully,

    --> then print its fd otherwise print error number.
    
*/

#include<stdio.h>
#include<errno.h>
#include<fcntl.h>


int main()
{   
    int fd = 0;
    fd = open("Marvellous.txt",O_RDONLY);   //Use to open file only for read

    printf("Value of fd is %d\n",fd);

    printf("Value of errno is %d\n",errno);
    
    return 0;
}