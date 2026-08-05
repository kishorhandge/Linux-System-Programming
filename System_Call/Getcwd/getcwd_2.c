/*
    This program prints the current working directory
    using the getcwd() system call.
*/

#include<stdio.h>     // For printf()
#include<string.h>    // For memset()
#include<unistd.h>    // For getcwd()

int main()
{   
    char Arr[50];                              // Array to store current directory path

                                            
    memset(Arr, '\0', sizeof(Arr));            // Initialize the array with null characters

     
    getcwd(Arr, sizeof(Arr));                   // Get the current working directory path

    
    printf("Current directory name: %s\n", Arr);  // Display the current directory path

    return 0;         
}
/*
| Upper code is not give the path name becuase of pc issue |

#include<stdio.h>
#include<unistd.h>

int main()
{   
    char Arr[1024];   // Bigger buffer

    // getcwd returns NULL if it fails
    if(getcwd(Arr, sizeof(Arr)) == NULL)
    {
        perror("getcwd failed");
        return 1;
    }

    printf("Current directory path: %s\n", Arr); 

    return 0;
}


*/