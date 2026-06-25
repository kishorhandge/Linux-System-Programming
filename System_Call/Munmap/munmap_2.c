/*
    --> Program demonstrates file-backed memory mapping using mmap().
    --> A file is created and resized.
    --> File content is accessed using memory mapping.
*/

#include<stdio.h>          // Provides printf() function
#include<string.h>         // Provides strcpy() function
#include<sys/mman.h>       // Provides mmap() and munmap()
#include<sys/stat.h>       // Provides struct stat and fstat()
#include<fcntl.h>          // Provides open() and file flags
#include<unistd.h>         // Provides ftruncate() and close()

int main()
{   
    int fd = 0;            // File descriptor
    char *ptr = NULL;      // Pointer to mapped memory
    struct stat st;        // Structure to store file information

    fd = open("PUNE.txt", O_RDWR | O_CREAT, 0777); // open(): create/open file

    ftruncate(fd, 4096);   // ftruncate(): set file size to 4096 bytes

    fstat(fd, &st);        // fstat(): get file size information

    ptr = mmap(
            NULL,          // Let kernel choose address
            st.st_size,    // Map entire file size
            PROT_READ | PROT_WRITE,   // Read and write permissions
            MAP_SHARED,    // Changes reflect in file
            fd,            // File descriptor
            0);            // Offset

    strcpy(ptr, "Jay ganesh...");     // Write data to mapped file memory

    printf("Data from mapped memory is : %s\n", ptr); // Read data

    munmap(ptr, st.st_size); // munmap(): unmap file from memory

    close(fd);               // close(): close file descriptor
    
    return 0;                // Normal program termination
}
