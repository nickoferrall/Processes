// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
    // Your code here

    int fd[2];

    // create pipe descriptors. Try to print this**
    pipe(fd);

    // fork() return 0 for the child, not 0 for the parent
    if (fork() != 0)
    {

        // close write descriptor only
        close(fd[1]);

        read(fd[0], &msg1, sizeof(msg1));
        read(fd[0], &msg2, sizeof(msg2));
        read(fd[0], &msg3, sizeof(msg3));
        printf("Parent(%d) reading.. %s\n", getpid(), msg1);
        printf("Parent(%d) reading.. %s\n", getpid(), msg2);
        printf("Parent(%d) reading.. %s\n", getpid(), msg3);

        // close the read descriptor
        close(fd[0]);
    }
    else // child: reading only so close the write descriptor
    {
        // close read descriptor
        close(fd[0]);

        // now write the data
        write(fd[1], &msg1, sizeof(msg1));
        write(fd[1], &msg2, sizeof(msg2));
        write(fd[1], &msg3, sizeof(msg3));
        printf("Child(%d) writing.. %s\n", getpid(), msg1);
        printf("Child(%d) writing.. %s\n", getpid(), msg2);
        printf("Child(%d) writing.. %s\n", getpid(), msg3);

        // close write descriptor
        close(fd[1]);
    }

    return 0;
}
