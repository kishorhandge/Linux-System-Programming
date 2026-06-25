/*
    --> Program demonstrates memory allocation and deallocation using mmap() and munmap().
    --> mmap() allocates anonymous memory.
    --> munmap() releases the mapped memory.
*/

#include<stdio.h>          // Provides printf() function
#include<string.h>         // Provides strcpy() function
#include<sys/mman.h>       // Provides mmap() and munmap() functions

int main()
{
    char *ptr = NULL;      // Pointer to mapped memory

    ptr = mmap(
            NULL,          // Let kernel choose memory address
            4096,          // Size of memory (one page)
            PROT_READ | PROT_WRITE,   // Read and write permissions
            MAP_PRIVATE | MAP_ANONYMOUS, // Anonymous private mapping
            -1,            // No file descriptor
            0);            // Offset

    strcpy(ptr, "Jay ganesh...");     // Copy data to mapped memory

    printf("Data from mapped memory is : %s\n", ptr); // Print stored data

    munmap(ptr, 4096);     // munmap(): release mapped memory

    return 0;              // Normal program termination
}
