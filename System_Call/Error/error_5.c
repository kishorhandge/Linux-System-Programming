#include<stdio.h>      // used for input/output functions like printf
#include<errno.h>      // used to get error numbers when a system call fails
#include<fcntl.h>      // used for file opening and file control operations
#include<string.h>     // used for string functions like strerror()

int main()
{   
    int fd = 0;

   
    fd = open("Marvellous.txt", O_RDONLY);                      // tries to open Marvellous.txt file in read-only mode

   
    printf("Value of fd is %d\n", fd);                          // prints file descriptor (fd)

     
    if(errno != 0)                                              // check if any error has occurred (errno becomes non-zero)
    {
         
        switch(errno)
        {
            case ENOENT :
                 
                printf("There is no such file. Create the file and try again.\n");  // ENOENT = No such file or directory
                break;

            case EACCES :
                
                printf("Unable to access the file. Permission denied.\n");           // EACCES = Permission denied
                break;

            default :
              
                printf("%s\n", strerror(errno));                                        // prints human-readable error message
        }
    }

    return 0;
}
