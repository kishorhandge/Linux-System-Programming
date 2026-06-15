/****************************************************************************************
* Program Name : IPC Key Generation using ftok()
* Description  : This program generates a unique IPC key using the ftok() function.
*                The key is created using a file name and a project identifier.
*                This key can be used for IPC mechanisms like shared memory,
*                message queues, or semaphores.
****************************************************************************************/

#include <sys/ipc.h>   // Contains IPC related functions like ftok()
#include <stdio.h>    // Contains printf()

int main()
{
    key_t key;   // Variable to store the generated IPC key

    // Generate IPC key using file name and project identifier
    key = ftok("LSP.txt", 's');

    // Print the generated key
    printf("Key is : %d\n", key);

    return 0;    // Return success
}
