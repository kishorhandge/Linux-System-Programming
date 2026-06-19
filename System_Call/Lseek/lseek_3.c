/*
    --> It opens the file "LSP.txt" in read-only mode.

    --> It first reads 10 bytes from the beginning of the file.

    --> Then it clears the buffer again to avoid mixing old data.

    --> It moves the file pointer 5 bytes forward from the current position.

    --> Then it reads the next 11 bytes from the new position.

    --> Finally, it prints the data and closes the file.
*/

#include<stdio.h>                                           // used for printf()
#include<unistd.h>                                          // used for read(), lseek(), close()
#include<fcntl.h>                                           // used for open()
#include<string.h>                                          // used for memset(), strerror()
#include<errno.h>                                           // used for error numbers

#define SIZE_BUFFER 100                                     // buffer size is 100 bytes

int main()
{
    int fd = 0;                                             // to store file descriptor

    char Buffer[SIZE_BUFFER];                               // buffer to store data read from file

    int iRet = 0;                                           // stores return values of system calls

    memset(Buffer,'\0',SIZE_BUFFER);                        // clear buffer (set all bytes to NULL)

    fd = open("LSP.txt",O_RDONLY);                          // open LSP.txt in read-only mode

    if(fd < 0)                                              // check if file failed to open
    {
        printf("unable to open the file:\n");               // print error message

        printf("reason: %s\n",strerror(errno));             // print human-readable reason
        return -1;                                          // stop program
    }
    
    printf("file successfully opened with fd : %d\n",fd);   // file opened

    iRet = read(fd,Buffer,10);                              // read first 10 bytes

    memset(Buffer,'\0',SIZE_BUFFER);                        // clear buffer again

    iRet = lseek(fd,5,SEEK_CUR);                            // move file pointer 5 bytes forward

    printf("updated file offset is %d\n",iRet);             // print new pointer position

    iRet = read(fd,Buffer,11);                              // read next 11 bytes

    printf("data from file is %s\n",Buffer);                // print data

    close(fd);                                              // close the file

    return 0;                                               // end program
}
