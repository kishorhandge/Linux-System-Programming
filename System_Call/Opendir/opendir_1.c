/*
    program discription->

    1) opendir("foldername") opens the folder and returns a pointer to it.
    2) If it fails, it returns NULL and errno stores the error.
    3) Here we open the folder named "Data" and check if it works.
*/

#include<stdio.h>                                   // For printf
#include<unistd.h>                                  // For system calls like chdir(), getcwd()
#include<fcntl.h>                                   // For file operations (optional here)
#include<string.h>                                  // For string functions like strerror()
#include<errno.h>                                   // For checking error numbers if a system call fails
#include<sys/stat.h>                                // For folder/file info and permissions (optional here)
#include<sys/types.h>                               // For system data types (used with dirent and other sys calls)
#include<dirent.h>                                  // For directory handling functions like opendir(), readdir()

int main()
{
    DIR *dp = NULL;                                 // Pointer to hold the directory information

    dp = opendir("./Data");                         // Try to open folder "Data"

    if(dp == NULL)                                  // Check if folder opening failed
    {
        printf("%s\n", strerror(errno));            // Print the error message
        return -1;                                  // Exit the program with error
    }
    else
    {
        printf("Directory gets successfully opened\n"); // Success message
    }
    
    return 0;         
}
