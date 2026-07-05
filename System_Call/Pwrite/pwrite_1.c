#include<stdio.h>                               // For printf
#include<unistd.h>                              // For read() and close()
#include<fcntl.h>                               // For open() and O_RDONLY
#include<string.h>                              // For string handling functions like strerror()
#include<errno.h> 
#include<stdlib.h>

int main()
{
    int fd = 0;

    off_t offset = 0;
    int iRet = 0;

    char Buffer[100] = "Pune";


    fd = open("./LSP.txt",O_WRONLY | O_APPEND);


    iRet = pwrite(fd,Buffer,4,10);

    offset = lseek(fd,0,SEEK_CUR);

    printf("Current offset is :%ld\n",offset);         //15

    return 0;
}