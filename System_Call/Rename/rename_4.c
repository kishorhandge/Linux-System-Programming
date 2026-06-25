/*
    --> Program demonstrates opening, reading, and renaming a file in Linux.
    --> It opens "process.txt" in read-only mode using open().
    --> The file is then renamed to "./Test/Hello.txt" using rename().
    --> Error handling is done using errno and strerror() if open() or rename() fails.
    --> Reads first 50 bytes from the original file and displays them.
*/

#include<stdio.h>                           // For printf()
#include<string.h>                          // For strerror()
#include<errno.h>                           // For error handling
#include<fcntl.h>                           // For open() and O_RDONLY
#include<unistd.h>                          // For read() and close()

int main()
{   
    int iRet = 0;                           // Variable to store return values
    int fd = 0;                             // File descriptor
    char Arr[100];                          // Buffer to store file data

    fd = open("./process.txt", O_RDONLY);   // Open file in read-only mode

    if(fd == -1)                            // Check if file open failed
    {
        printf("Unable to open file\n");   // Print error message
        return -1;                          // Exit on failure
    }

    iRet = rename("./process.txt", "./Test/Hello.txt"); // Attempt to rename file

    if(iRet == 0)                            // Check if rename succeeded
    {
        printf("Rename sucessful\n");        // Print success message
    }
    else                                     // If rename failed
    {
        printf("%s\n", strerror(errno));     // Print error message
        return -1;                           // Exit on failure
    }

    iRet = read(fd, Arr, 50);                // Read first 50 bytes from file

    if(iRet != 0)                            // Check if data was read
    {
        printf("Data from file is %s\n", Arr); // Display file data
    }

    close(fd);                               // Close the file

    return 0;                                // End of program
}
