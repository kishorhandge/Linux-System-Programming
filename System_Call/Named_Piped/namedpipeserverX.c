/****************************************************************************************
* Program Name : Named Pipe (FIFO) Server – Write Data
* Description  : This program creates a named pipe (FIFO) and writes data into it.
*                The server opens the FIFO in write-only mode.
*                Data written by the server can be read by a client process.
*                After communication, the FIFO is removed from the system.
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <stdlib.h>     // For general utility functions
#include <sys/types.h>  // For system data types
#include <sys/stat.h>   // For mkfifo()
#include <fcntl.h>      // For open()
#include <unistd.h>     // For write(), close(), unlink()

int main()
{
    int fd = 0;         // File descriptor for named pipe
    int iRet = 0;       // Variable to store return value

    // Create named pipe (FIFO)
    iRet = mkfifo("/tmp/marvellous", 0666);

    // Check if FIFO creation failed
    if(iRet == -1)
    {
        printf("Unable to create named pipe\n");
        return -1;
    }

    // Open the named pipe in write-only mode
    fd = open("/tmp/marvellous", O_WRONLY);

    // Check if opening pipe failed
    if(fd == -1)
    {
        printf("Unable to open named pipe\n");
        return -1;
    }

    // Write data into the pipe
    write(fd, "Jay Ganesh", 10);

    printf("Data gets successfully written into the pipe by the server\n");

    // Close the named pipe
    close(fd);

    // Remove the named pipe from the system
    unlink("/tmp/marvellous");

    return 0;           // Return success
}
