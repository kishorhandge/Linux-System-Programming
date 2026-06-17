/*
    This program opens "LSP.txt" in read-only mode and reads the first 10 bytes.
    Then it closes the file, reopens it, and reads the first 10 bytes again.

    1) open() opens the file and returns a file descriptor (fd).
    2) read() reads bytes from the file into a buffer.
    3) memset() clears the buffer before reading to avoid old data mix-up.
    4) Closing and reopening the file resets the file pointer to the beginning.
    5) strerror(errno) gives the reason if open() fails.
*/

#include<stdio.h>                               // For printf
#include<unistd.h>                              // For read() and close()
#include<fcntl.h>                               // For open() and O_RDONLY
#include<string.h>                              // For memset() and strerror()
#include<errno.h>                                // For error handling if open/read fails

#define SIZE_BUFFER 100                         // Size of buffer for reading file

int main()
{
    int fd = 0;                                 // File descriptor
    char Buffer[SIZE_BUFFER];                   // Buffer to store file data
    int iRet = 0;                               // Number of bytes read

    memset(Buffer, '\0', SIZE_BUFFER);          // Initialize buffer

    fd = open("LSP.txt", O_RDONLY);             // Open the file first time

    if(fd < 0)                                  // Check if open failed
    {
        printf("Unable to open the file\n");
        printf("Reason: %s\n", strerror(errno));
        return -1;
    }

    printf("File successfully opened with fd: %d\n", fd);

    iRet = read(fd, Buffer, 10);                // Read first 10 bytes
    printf("%d bytes successfully read\n", iRet);
    printf("Data from file: %s\n", Buffer);

    close(fd);                                  // Close the file

                                            // Reopen the file to read again from start
    fd = open("LSP.txt", O_RDONLY);         // IMPORTANT: reopening resets file pointer
    memset(Buffer, '\0', SIZE_BUFFER);      // Clear buffer before reading

    iRet = read(fd, Buffer, 10);            // Read first 10 bytes again
    printf("%d bytes successfully read\n", iRet);
    printf("Data from file: %s\n", Buffer);

    close(fd);                           // Close the file

    return 0;                             
}
