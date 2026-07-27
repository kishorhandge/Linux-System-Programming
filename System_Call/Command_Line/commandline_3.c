/*
    -->To print all command-line arguments passed to the program, including the program name itself.

    -->To display the total number of command-line arguments.

*/

#include<stdio.h>

int main(int argc,char *argv[])
{   
    int iCnt = 0;

    printf("Number of command line args  are :%d\n",argc);

    for(iCnt =0;iCnt<argc;iCnt++)
    {
        printf("%s\n",argv[iCnt]);
    }
    

    return 0;

}