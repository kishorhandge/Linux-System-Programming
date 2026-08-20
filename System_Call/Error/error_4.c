#include<stdio.h>      // used for printf() input/output functions
#include<errno.h>      // used to get error numbers when a system call fails
#include<fcntl.h>      // used for file opening and file control operations
#include<string.h>     // used for string functions like strerror()

int main()
{   
    int fd = 0;

     
    fd = open("LSP.txt", O_RDONLY);                             // tries to open LSP.txt file in read-only mode

    
    printf("Value of fd is %d\n", fd);                          // prints the file descriptor value

   
    if(errno != 0)
    {
         
        printf("Value of errno is : %d\n", errno);              // prints the error number  

         
        printf("error statement : %s\n", strerror(errno));      // prints a human-readable error message      
    }

    return 0;
}
