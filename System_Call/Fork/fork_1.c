/*
    --> The program calls fork() to create a new child process

    -->After fork(), two processes start running the same code

            -->Parent process

            -->Child process

*/

#include<stdio.h>
#include<unistd.h>

int main()
{

    pid_t pid = 0;                  //Use to store process IDs."

    pid = fork();

    printf("%d\n",pid);
    
    return 0;
}
