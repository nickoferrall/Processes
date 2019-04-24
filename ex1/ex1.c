// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here

    int x = 8;
    printf("I'm in the parent. Here's x: %d\n", x);

    pid_t pid = fork();

    if (pid == 0)
    {
        printf("I'm in the child process. Here's x: %d\n", x);
        printf("I'm in the child. Pid is.. %d\n", getpid());
        x = 7;
        printf("Despues! I'm in the child process. Here's x: %d\n", x);
        printf("Despues! I'm in the child. Pid is.. %d\n", getpid());
    }
    else
    {
        printf("I'm in the other child. X is.. %d\n", x);
        printf("I'm in the other child. Pid is.. %d\n", getpid());
        x = 100;
        printf("Despues! I'm in the other child. X is.. %d\n", x);
        printf("Despues! I'm in the other child. Pid is.. %d\n", getpid());
    }

    printf("X from the end.. %d\n", x);

    return 0;
}
