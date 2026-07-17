/*
    --> Program demonstrates the use of readlink() in Linux.
    --> It reads the symbolic link "./Test/LSPl.txt".
    --> The target path of the symbolic link is stored in the buffer.
    --> Error handling is done using errno and strerror() if readlink() fails.
    --> The data read from the symbolic link is displayed.
*/

#include<stdio.h>                                           // For printf()
#include<unistd.h>                                          // For readlink()
#include<fcntl.h>                                           // For file control options (not used here but included)
#include<string.h>                                          // For memset()
#include<errno.h>                                           // For error handling

int main()
{   
    char Path[100];                                         // Buffer to store target of symbolic link
    int iRet = 0;                                           // Return value from readlink()

    memset(Path,'\0',sizeof(Path));                         // Initialize buffer

    iRet = readlink("./Test/LSPl.txt", Path, sizeof(Path)); // Read symbolic link

    if(iRet == -1)                                          // Check if readlink failed
    {
        printf("%s\n", strerror(errno));                    // Print error message
        return -1;                                          // Exit on failure
    }

    Path[iRet] = '\0';                                      // Null-terminate the string

    printf("data from readlink is %s\n", Path);             // Display target path

    return 0;               
}
