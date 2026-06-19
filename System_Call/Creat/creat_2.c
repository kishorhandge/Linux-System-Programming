/*
    --> This program creates a file using a name provided by the user as command-line argument.

    --> If the file does not exist, it will create a new file.

    --> If the file already exists, it will truncate the file (e.g clear all its content).

    --> If the file is created successfully, it prints the file descriptor (a number given by the operating system).

    --> If the file creation fails (for e.g due to permissions), it prints an error message.


*/


#include<fcntl.h>
#include<stdio.h>

int main(int argc,char *argv[])
{
    int fd = 0;
    fd = creat(argv[1],0777);           // filename to create, file permissions

    if(fd == -1)
    {
        printf("Unable to create the file:\n");
    }
    else
    {
        printf("File gets succesfully created with fd : %d\n",fd);
    }



    return 0;
}

// Run command --> creat_2.c -o create

// ./create demo.c