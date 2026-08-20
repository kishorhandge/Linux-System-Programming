/*
    --> Program is used to display the error number.

    --> The program simply prints the current value of errno

    --> Occures when system call() is fails.

*/

#include<stdio.h>
#include<errno.h>      //gives us access to the special variable errno.

int main()
{   
    printf("demonstration of errno : \n");
    printf("%d\n",errno);
    
    return 0;
}