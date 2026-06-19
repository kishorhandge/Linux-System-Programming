/*
    Program is used to create file named as LSP.txt

    using CREAT() system call and give all permission

*/

#include<fcntl.h>
#include<stdio.h>

int main()
{
    int fd = 0;
    fd = creat("LSP.txt",0777);

    if(fd == -1)                                                
    {
        printf("Unable to create the file:\n");                     //if unable to create a file.
    }
    else
    {
        printf("File gets succesfully created with fd : %d\n",fd);  // if file gets succesfully create.
    }

    return 0;
}