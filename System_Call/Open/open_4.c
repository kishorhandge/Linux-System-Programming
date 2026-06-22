/*
    This program tries to create second.c file,

    If file is exist delete that file using TRUNC() system call.


*/

#include<fcntl.h> //file control
#include<stdio.h>
 

int main()
{

    int fd = 0;
    fd = open("second.c",O_CREAT | O_TRUNC,0777);                   //name,mode ,access

    if(fd == -1)
    {
        printf("Unable to create file : \n");                       //if file creation is failed
    }
    else
    {
        printf("File gets succesfully created with fd %d\n",fd);    //if file creation is succesfully.    
    }

    return 0;
}