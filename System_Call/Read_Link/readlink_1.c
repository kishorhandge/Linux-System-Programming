/*
    --> Program demonstrates opening a file in read-only mode in Linux.
    --> It tries to open "LSPl.txt" from the "./Test" directory.
    --> Error handling is done using errno and strerror() if file cannot be opened.
    --> File descriptor is displayed if the file is successfully opened.
*/

#include<stdio.h>                           // For printf()
#include<unistd.h>                          // For close() system call
#include<fcntl.h>                           // For open() system call and O_RDONLY
#include<string.h>                          // For strerror()
#include<errno.h>                           // For error handling

int main()
{   
    int fd = 0;                                                     // File descriptor

    fd = open("./Test/LSPl.txt", O_RDONLY);                         // Attempt to open file

    if(fd == -1)                                                    // Check if file open failed
    {
        printf("Unable to open file %s\n", strerror(errno));        // Print error
        return -1;                                                  // Exit on failure
    }

    printf("File opened with fd: %d\n", fd);                        // Display file descriptor

    close(fd);                                                      // Close the file

    return 0;              
}
