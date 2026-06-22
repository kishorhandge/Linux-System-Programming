/*              * program description *

    -->Program tries to open "first.c" in read-write mode.

    -->if opening fails → prints an error message.

    -->If successful → prints the file descriptor.    
*/


#include<fcntl.h>                       //This header file is needed for functions like open(), and for constants like O_RDWR (read-write mode).
#include<stdio.h>
 

int main()
{

    int fd = 0;                         //fd = file descriptor

    fd = open("first.c",O_RDWR);        //This line tries to open the file first.c in read + write mode.

    if(fd == -1)
    {
        printf("Unable to open file : \n");
    }
    else
    {
        printf("File gets succesfully opened with fd %d\n",fd);
    }

    return 0;
}