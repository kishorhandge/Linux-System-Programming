/*
    --> Program demonstrates creating a symbolic link in Linux using symlink().
    --> It tries to create a symbolic link "Hello.txt" pointing to "DemoX.txt".
    --> symlink() returns 0 on success and -1 on failure.
    --> Error handling is done using errno and strerror() if creation fails.
    --> Success or failure message is displayed accordingly.
*/

#include<stdio.h>                           // For printf()
#include<unistd.h>                          // For symlink()
#include<fcntl.h>                           // For file control options
#include<sys/stat.h>                        // For file information
#include<string.h>                          // For strerror()
#include<errno.h>                           // For error handling

int main()
{   
    int iRet = 0;                           // Variable to store return value of symlink()

    iRet = symlink("DemoX.txt", "Hello.txt"); // Attempt to create symbolic link

    if(iRet == 0)                           // Check if symlink creation succeeded
    {
        printf("symlink is succesfully\n"); // Print success message
    }
    else                                    // If symlink creation failed
    {
        printf("%s\n", strerror(errno));    // Print error message
    }

    return 0;                               // End of program
}
