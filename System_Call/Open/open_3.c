/*
    This program tries to open second.c file,

    If file is not exist create that file using CREAT() system call.

    And give all permission (7 = read + write + execute)

    owner , group , others (give all permission to everyone)



*/


#include<fcntl.h> //file control
#include<stdio.h>
 

int main()
{

    int fd = 0;
    fd = open("second.c",O_CREAT,0777); //name,mode ,access

    if(fd == -1)
    {
        printf("Unable to create file : \n");
    }
    else
    {
        printf("File gets succesfully created with fd %d\n",fd);
    }

    return 0;
}