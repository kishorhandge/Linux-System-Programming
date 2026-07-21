/*
    --> Program demonstrates directory traversal in Linux.
    --> It reads and displays all files from a directory.
    --> Directory entries are accessed using readdir() system call.
    --> Error handling is done using errno and strerror() if directory cannot be opened.
*/

#include<stdio.h>                           // For printf()
#include<unistd.h>                          // For POSIX system calls
#include<fcntl.h>                           // For file control options
#include<string.h>                          // For strerror()
#include<errno.h>                           // For error handling
#include<sys/stat.h>                        // For file information
#include<sys/types.h>                       // For system data types
#include<dirent.h>                          // For directory handling functions

int main()
{
    DIR *dp = NULL;                         // Directory stream pointer
    struct dirent *ptr = NULL;              // Directory entry pointer

    dp = opendir("./Data");                 // Open directory named "Data"

    if(dp == NULL)                          // Check if directory open failed
    {
        printf("%s\n", strerror(errno));   // Print error message using errno
        return -1;                         // Exit on failure
    }

    // Read and display all directory entries
    // The loop below is kept exactly as provided by the user
    while(ptr = readdir(dp))
    {
        printf("INode number :%ld\n",ptr->d_ino);
    
    
        //fd = open(ptr->d_name,O_RDONLY);
        //iRet = read(fd,Arr,sizeof(Arr));
        
        printf("file Name :%s\n",ptr->d_name);
    }

    closedir(dp);                           // Close the directory

    return 0;                       
}
