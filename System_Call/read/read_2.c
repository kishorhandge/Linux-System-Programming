/*
    This program opens a file "LSP.txt" in read-only mode,
    reads the first 10 bytes, and displays them on the screen.

    1) open() opens the file and returns a file descriptor (fd).
    2) read() reads bytes from the file into a buffer.
    3) memset() is used to clear the buffer before reading.
    4) close() closes the file after reading.
    5) strerror(errno) gives the reason if open() fails.
*/

#include<stdio.h>                               // For printf
#include<unistd.h>                              // For read() and close()
#include<fcntl.h>                               // For open() and O_RDONLY
#include<string.h>                              // For memset() and strerror()
#include<errno.h>                               // For checking errors if open/read fails

#define SIZE_BUFFER 100                         // Size of buffer for reading file

int main()
{
    int fd = 0;                                 // File descriptor

    char Buffer[SIZE_BUFFER];                   // Buffer to store file data
    int iRet = 0;                               // Number of bytes read

    memset(Buffer, '\0', SIZE_BUFFER);          // Initialize buffer with null characters

    fd = open("LSP.txt", O_RDONLY);             // Open the file in read-only mode

    if(fd < 0)                                  // Check if file open failed
    {
        printf("Unable to open the file\n");
        printf("Reason: %s\n", strerror(errno)); // Print reason
        return -1;
    }

    printf("File successfully opened with fd: %d\n", fd);

    iRet = read(fd, Buffer, 10);                    // Read first 10 bytes from file

    printf("%d bytes successfully read\n", iRet);
    printf("Data from file: %s\n", Buffer);         // Display the data

    close(fd);                                      // Close the file

    return 0;                           
}
