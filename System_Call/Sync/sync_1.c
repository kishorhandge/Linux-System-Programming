/*
    --> Program demonstrates writing data to a file in Linux using open() and write().
    --> It opens "Demo.txt" with O_CREAT, O_WRONLY, and O_APPEND flags (creates if not exists, write-only, append mode).
    --> File permissions are set to 0777.
    --> Writes the string "indiaismycountry" to the file using write().
    --> Error handling is done using errno and strerror() if opening the file fails.
    --> Displays the number of bytes written and closes the file.
*/

#include<stdio.h>                               // For printf()
#include<unistd.h>                              // For write() and close()
#include<fcntl.h>                               // For open() and file flags
#include<string.h>                              // For strerror()
#include<errno.h>                               // For error handling

int main()
{
    int fd = 0;                                     // File descriptor
    char Buffer[] = "indiaismycountry";             // Data to write
    int iRet = 0;                                   // Variable to store number of bytes written

    fd = open("Demo.txt", O_CREAT | O_WRONLY | O_APPEND, 0777); // Open file in append mode, create if not exists, set permissions

    if(fd < 0)                                                  // Check if file open failed
    {
        printf("unable to open the file:\n");                   // Print error message
        printf("reason: %s\n", strerror(errno));                // Print reason for failure
        return -1;                                              // Exit on failure
    }

    printf("file successfully open with fd :%d\n", fd);         // Display file descriptor

    iRet = write(fd, Buffer, 16);                               // Write 16 bytes from buffer to file

    printf("%d bytes gets successfully written\n", iRet);       // Display number of bytes written

    close(fd);                                                  // Close the file

    return 0;                                
}
