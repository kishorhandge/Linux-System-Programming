/*
    --> Program demonstrates renaming a file in Linux using the rename() system call.
    --> It tries to rename "DemoX.txt" to "Demo.txt".
    --> rename() returns 0 on success and -1 on failure.
    --> Error handling is done using errno and strerror() if renaming fails.
    --> Success or failure message is displayed accordingly.
*/

#include<stdio.h>                               // For printf()
#include<string.h>                              // For strerror()
#include<errno.h>                               // For error handling

int main()
{   
    int iRet = 0;                                 // Variable to store return value of rename()

    iRet = rename("DemoX.txt", "Demo.txt");      // Attempt to rename file

    if(iRet == 0)                                // Check if rename succeeded
    {
        printf("Rename successful\n");          // Print success message
    }
    else                                        // If rename failed
    {
        printf("%s\n", strerror(errno));        // Print error message
        return -1;                              // Exit on failure
    }

    return 0;                
}
