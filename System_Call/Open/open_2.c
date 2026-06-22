/*                             

    -->Program tries to open second.c.

    -->Uses open() → a system call.

    -->fd = -1 means failure.

    -->Positive fd means success.


*/

#include<fcntl.h>                               //Needed for the open() system call. Provides constants like O_RDWR, O_RDONLY, O_WRONLY
#include<stdio.h>
 

int main()
{

    int fd = 0;                                 //fd means file descriptor.

    fd = open("second.c",O_RDWR);               //This line tries to open second.c in read-write mode.

    if(fd == -1)
    {
        printf("Unable to open file : \n");     //if files open fail ir return -1
    }
    else
    {
        printf("File gets succesfully opened with fd %d\n",fd); //if file get succesfully opened
    }

    return 0;
}