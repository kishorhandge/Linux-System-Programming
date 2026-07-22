/*
    --> Program demonstrates deleting a file in Linux using unlink().
    --> It deletes the file "LSP.txt".
    --> unlink() returns 0 on success and -1 on failure.
    --> Success message is displayed if the file is deleted.
*/

#include<stdio.h>                       // For printf()
#include<unistd.h>                      // For unlink()
#include<fcntl.h>                       // For file control options (not used here, included for reference)
#include<sys/stat.h>                    // For file status (not used here, included for reference)

int main()
{   
    int iRet = 0;                       // Variable to store return value of unlink()

    iRet = unlink("LSP.txt");           // Delete the file "LSP.txt"

    if(iRet == 0)                       // Check if unlink succeeded
    {
        printf("Unlink is successfully\n");  // Print success message
    }

    return 0;                    
}
