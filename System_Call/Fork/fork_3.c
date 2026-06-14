/*
    -->fork() - used to create a new process

    -->getpid() - get current process ID

    -->getppid() - get parent’s process ID

    -->execl() - used to run another program

------------------------------------------------------------------------------------------

    -->fork() creates a parent and child

    -->Child prints its details and then runs firstExe

    -->Parent prints its own details


*/
#include<stdio.h>
#include<unistd.h>

int main()
{

    pid_t pid = 0;              // It will store the value returned by fork().

    pid= fork();

    if(pid == 0)
    {
        printf("CHILD SAYS : PID of current process : %d,PID of parent : %d,return value of fork is %d\n",getpid(),getppid(),pid);

        execl("./firstExe","",NULL);
    }
    else
    {
        printf("PARENT SAYS : PID of current process : %d,PID of parent : %d,return value of fork is %d\n",getpid(),getppid(),pid);
    }
 
    
    return 0;
}
