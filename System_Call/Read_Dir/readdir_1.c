/*
    --> Program demonstrates directory handling in Linux.

    --> It opens a directory using opendir() system call.

    --> Directory entries are read using readdir().

    --> Inode number and file name of entries are displayed.

    --> Error message is shown if directory open fails.
*/


#include<stdio.h>          // For printf()
#include<unistd.h>         // For POSIX system calls
#include<fcntl.h>          // For file control options
#include<string.h>         // For strerror()
#include<errno.h>          // For error handling
#include<sys/stat.h>       // For file information
#include<sys/types.h>      // For system data types
#include<dirent.h>         // For directory handling functions

int main()
{
    DIR *dp = NULL;                                     // Directory stream pointer

    struct dirent *ptr = NULL;                          // Directory entry pointer

    dp = opendir("./Data");                             // Open directory named "Data"

    if(dp == NULL)                                      // Check if directory open failed
    {
        printf("%s\n", strerror(errno));                  // Print error message
        return -1;                                        // Exit on failure
    }

    ptr = readdir(dp);                                  // Read first directory entry

    printf("INode number : %ld\n", ptr->d_ino);         // Print inode number

    printf("file Name : %s\n", ptr->d_name);            // Print file name

    ptr = readdir(dp);                                  // Read second directory entry
    printf("INode number : %ld\n", ptr->d_ino);         // Print inode number
    printf("file Name : %s\n", ptr->d_name);            // Print file name

    ptr = readdir(dp);                                  // Read third directory entry
    printf("INode number : %ld\n", ptr->d_ino);         // Print inode number
    printf("file Name : %s\n", ptr->d_name);            // Print file name

    return 0;                      
}
