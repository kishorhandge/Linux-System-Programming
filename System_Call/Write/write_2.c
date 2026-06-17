/*
    --> Program demonstrates writing data to an existing file in Linux using write().
    --> Opens "LSP.txt" in write-only mode (O_WRONLY).
    --> Writes 10 bytes of "HelloWorld" to the file.
    --> This may overwrite existing content at the beginning of the file.
    --> Displays the number of bytes successfully written.
    --> Error handling is done using errno and strerror().
*/

#include<stdio.h>                                     // For printf()
#include<unistd.h>                                    // For write() and close()
#include<fcntl.h>                                     // For open() and file flags
#include<string.h>                                    // For strerror()
#include<errno.h>                                     // For error handling

int main()
{
    int fd = 0;                                         // File descriptor
    char Buffer[] = "HelloWorld";                       // Data to write
    int iRet = 0;                                       // Variable to store number of bytes written

    fd = open("LSP.txt", O_WRONLY);                     // Open file in write-only mode

    if(fd < 0)                                          // Check if file open failed
    {
        printf("unable to open the file:\n");           // Print error message
        printf("reason: %s\n", strerror(errno));        // Print reason for failure
        return -1;                                      // Exit on failure
    }

    printf("file successfully open with fd :%d\n", fd);     // Display file descriptor

    iRet = write(fd, Buffer, 10);                           // Write 10 bytes to the file (may overwrite existing content)
    printf("%d bytes gets successfully written\n", iRet);   // Display number of bytes written

    close(fd);                                              // Close the file

    return 0;                                
}
