#include<stdio.h>
#include<unistd.h>

int main()
{
    void *ptr = NULL;


    ptr = sbrk(100);        //ptr = malloc(100);

    printf("Current break value : %p\n",ptr);   //current break value  //4000

    ptr = sbrk(0);

    printf("Current break value : %p\n",ptr);       //4100

    ptr = sbrk(-100);       //free(ptr);

    printf("Current break value : %p\n",ptr);       //4100

    ptr = sbrk(0);

    printf("Current break value : %p\n",ptr);       //4000

    return 0;
}