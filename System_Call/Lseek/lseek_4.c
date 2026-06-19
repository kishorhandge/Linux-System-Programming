/*
    -->It opens/creates a file named hole.txt.

    -->It moves the file pointer 4100 bytes ahead without writing anything.

    -->This creates an empty gap (hole) in the file.

    -->Then it writes "END" at that 4100th position.

    -->So the file becomes huge in size but most of it is empty.



*/

#include<stdio.h>                                                          
#include<unistd.h>                                                       
#include<fcntl.h>                                                           
#include<string.h>                                                           
#include<errno.h>                                                            

#define SIZE_BUFFER 100                                                 // buffer size is 100 bytes

int main()
{
    int fd = 0;                                                         // to store file descriptor

    char Buffer[SIZE_BUFFER];                                           // character buffer of 100 bytes

    int iRet = 0;                                                       // to store return value of system calls

    memset(Buffer,'\0',SIZE_BUFFER);                                    // make buffer empty (fill with NULL)

    fd = open("hole.txt",O_WRONLY | O_CREAT);                           // open or create file for writing

    if( fd < 0)                                                         // check if file opening failed
    {
        printf("unable to open the file:\n");                           // print error message

        printf("reason: %s\n",strerror(errno));                         // print human readable error
        return -1;                                                   
    }
    
    printf("file successfully open with fd :%d\n",fd);                  // file opened successfully

    iRet = lseek(fd,4100,SEEK_SET);                                     // move file pointer 4100 bytes from beginning

    printf("current offset is :%d\n",iRet);                             // print new file pointer position

    iRet = write(fd,"END",3);                                           // write 3 bytes ("END") at current position

    printf("%d bytes get written successfully \n",iRet);                // print how many bytes written

    close(fd);                                                          // close the file

    return 0;                                                            
}