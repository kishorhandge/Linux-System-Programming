/****************************************************************************************
* Program Name : Named Pipe (FIFO) Client
* Description  : This program acts as a client for a named pipe (FIFO).
*                It opens an existing named pipe in read-only mode.
*                The client reads data sent by the server through the pipe.
*                The received data is displayed on the screen.
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <stdlib.h>     // For general utility functions
#include <sys/types.h>  // For system data types
#include <sys/stat.h>   // For FIFO related functions
#include <fcntl.h>      // For open()
#include <unistd.h>     // For read() and close()

int main()
{
    int fd = 0;                 // File descriptor for named pipe
    int iRet = 0;               // Variable to store return value
    char Arr[100] = {'\0'};     // Buffer to store data

    // Open the named pipe in read-only mode
    fd = open("/tmp/marvellous", O_RDONLY);

    // Check if opening pipe failed
    if(fd == -1)
    {
        printf("Unable to open named pipe\n");
        return -1;
    }

    // Read 3 bytes of data from the pipe
    read(fd, Arr, 3);

    // Display success message and data
    printf("Data gets successfully read from the pipe by the client\n");
    printf("Data is : %s\n", Arr);

    // Close the named pipe
    close(fd);

    return 0;    // Return success
}
