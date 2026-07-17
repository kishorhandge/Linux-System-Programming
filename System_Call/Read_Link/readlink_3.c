/*
    --> Program demonstrates reading a symbolic link and accessing its target file in Linux.
    --> It reads the symbolic link "./Test/LSPl.txt" using readlink().
    --> The target file path from the symbolic link is stored in a buffer.
    --> The target file is then opened in read-only mode using open().
    --> First 10 bytes of the target file are read and displayed using read().
    --> Error handling is done using errno and strerror() for readlink() and open().
*/

#include<stdio.h>                                       // For printf()
#include<unistd.h>                                      // For read(), readlink(), close()
#include<fcntl.h>                                       // For open() and O_RDONLY
#include<string.h>                                      // For memset()
#include<errno.h>                                       // For error handling

int main()
{   
    char Path[100];                                         // Buffer to store target path from symbolic link
    int iRet = 0;                                           // Variable to store return values
    int fd = 0;                                             // File descriptor for target file
    char Arr[20];                                           // Buffer to read data from target file

    memset(Path,'\0',sizeof(Path));                         // Initialize buffer

    iRet = readlink("./Test/LSPl.txt", Path, sizeof(Path)); // Read symbolic link

    if(iRet == -1)                                          // Check if readlink failed
    {
        printf("%s\n", strerror(errno));                    // Print error message
        return -1;                                          // Exit on failure
    }

    Path[iRet] = '\0';                                      // Null-terminate the path string
    
    printf("data from readlink is %s\n", Path);             // Display symbolic link target

    fd = open(Path, O_RDONLY);                              // Open target file in read-only mode

    if(fd == -1)                                            // Check if opening target file failed
    {
        printf("Unable to open file \n");                   // Print error
        return -1;                                          // Exit on failure
    }

    iRet = read(fd, Arr, 10);                               // Read first 10 bytes from target file

    Arr[iRet] = '\0';                                       // Null-terminate the read string

    printf("data from orignal file : %s\n", Arr);           // Display file data

    close(fd);                                              // Close the target file

    return 0;                 
}
