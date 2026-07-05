/*
    This program is to make a hard link in C.

    1) link("source", "destination") makes a new file called "destination"
       that points to the same data as "source".

    2) If it works, it returns 0; if not, it returns -1.

    Here the destination is in a subfolder called "./Test/".
*/

#include<stdio.h>                                          // For printf
#include<unistd.h>                                         // For link system call
#include<fcntl.h>                                          // For file operations (optional)
#include<sys/stat.h>                                       // For file info and permissions (optional)

int main()
{
    int iRet = 0;                                           // To store the result of link

    iRet = link("./Demo.txt", "./Test/Demo.txt");           // Make a hard link in the Test folder

    if(iRet == 0)                                           // Check if link worked
    {
        printf("Link successful\n");                        // If yes, print success
    }
    else
    {
        perror("Link failed");                              // If not, print error
    }

    return 0;          
}
