/****************************************************************************************
* Program Name : Named Pipe (FIFO) Server – Creation
* Description  : This program creates a named pipe (FIFO) in the /tmp directory.
*                The named pipe is created using mkfifo() system call.
*                This pipe can be used for communication between processes.
*                A client process can open this pipe to read or write data.
****************************************************************************************/

#include <stdio.h>      // For printf()
#include <stdlib.h>     // For general utility functions
#include <sys/types.h>  // For system data types
#include <sys/stat.h>   // For mkfifo()
#include <fcntl.h>      // For file control operations
#include <unistd.h>     // For POSIX API

int main()
{
    int fd = 0;         // File descriptor (not used here)
    int iRet = 0;       // Variable to store return value of mkfifo()

    // Create named pipe (FIFO) with read-write permissions
    iRet = mkfifo("/tmp/marvellous", 0666);

    // Check if FIFO is created successfully
    if(iRet == 0)
    {
        printf("Named pipe gets successfully created\n");
    }

    return 0;           // Return success
}
