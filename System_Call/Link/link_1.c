/*
    This program shows how to create a hard link in C.

    1) link("source", "destination") creates a new file "destination"
       pointing to the same data as "source".

    2) Returns 0 if successful, -1 if it fails.
*/

#include<stdio.h>                                  // For input-output functions like printf()
#include<unistd.h>                                 // For system calls like link()
#include<fcntl.h>                                  // For file control operations (optional here)
#include<sys/stat.h>                               // For file information and permissions (optional here)

int main()
{
    int iRet = 0;                                   // Variable to store return value of link()

    iRet = link("Demo.txt", "DemoX.txt");           // Create hard link "DemoX.txt" pointing to "Demo.txt"

    if(iRet == 0)                                   // Check if link creation was successful
    {
        printf("Link is successful\n");             // Print success message
    }
    else
    {
        perror("Link failed");                      // Print error message if link fails
    }

    return 0;         
}
