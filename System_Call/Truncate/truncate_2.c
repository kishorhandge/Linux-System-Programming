/*
    --> Program demonstrates truncating a file in Linux using truncate().
    --> It truncates "Demo.txt" to 30 bytes.
    --> truncate() returns 0 on success and -1 on failure.
    --> Success or failure message is displayed accordingly.
*/

#include<stdio.h>                               // For printf()
#include<unistd.h>                              // For truncate()

int main()
{   
    int iRet = 0;                               // Variable to store return value of truncate()

    iRet = truncate("Demo.txt", 30);        // Truncate the file "Demo.txt" to 30 bytes

    if(iRet == 0)                           // Check if truncate succeeded
    {
        printf("truncate is done:\n");      // Print success message
    }
    else                                    // If truncate failed
    {
        printf("there is issue in truncate:\n");  // Print failure message
    }

    return 0;                             
}
