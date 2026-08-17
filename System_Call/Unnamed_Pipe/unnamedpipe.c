
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int pipefd[2] = {0,0};
    int iRet = 0;

    iRet = pipe(pipefd);

    if(iRet == 0)
    {
        printf("Unnamed pipe gets created:\n");
    }


    return 0;
}