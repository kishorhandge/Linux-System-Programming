#include<stdio.h>
#include<unistd.h>                                     //Used for functions like lseek() and close().
#include<fcntl.h>                                      //Used for open() system call to open files.
#include<string.h>
#include<errno.h>                                      //Used to get error numbers when file operations fail.

#define SIZE_BUFFER 100                                //This creates a constant named SIZE_BUFFER with value 100.

int main()
{
    int fd = 0;

    char Buffer[SIZE_BUFFER];
    int iRet = 0;

    memset(Buffer,'\0',SIZE_BUFFER);                    //it fills whole buffer with \0, makes the buffer empty       

    fd = open("LSP.txt",O_RDONLY);                      //open the file LSP.txt in read-only mode.

    if( fd < 0)
    {
        printf("uanable to open the file:\n");          //Unable to open file and gives human readable error.
        printf("reason: %s\n",strerror(errno));
        return -1;
    }
    
    printf("file sucessfully open with fd :%d\n",fd);   //succesfully opend.

    iRet = lseek(fd,10,SEEK_CUR);                       //lseek() is used to move the file pointer inside a file.                      
    
    printf("updated file offset is %d\n",iRet);         //prints the new position of the file pointer on the screen.

    close(fd);

    return 0;
}