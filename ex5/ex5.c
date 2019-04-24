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
    // int val = 0;

    // create pipe descriptors. Try to print this**
    pipe(fd);

    // fork() return 0 for the child, not 0 for the parent
    if (fork() != 0)
    {

        // close read descriptor only
        close(fd[0]);

        // send the value on the write descriptor
        // ** not sure what write descriptor is
        // ** find out what write does
        // val = 100;
        write(fd[1], &msg1, sizeof(msg1));
        write(fd[1], &msg2, sizeof(msg2));
        write(fd[1], &msg3, sizeof(msg3));
        printf("Parent(%d) send value: %s\n", getpid(), msg1);
        printf("Parent(%d) send value: %s\n", getpid(), msg2);
        printf("Parent(%d) send value: %s\n", getpid(), msg3);

        // close the write descriptor
        close(fd[1]);
    }
    else // child: reading only so close the write descriptor
    {
        // reading only so close the write descriptor
        close(fd[1]);

        // now read the data
        read(fd[0], &msg1, sizeof(msg1));
        read(fd[0], &msg1, sizeof(msg2));
        read(fd[0], &msg1, sizeof(msg3));
        printf("Child(%d) received value: %s\n", getpid(), msg1);
        printf("Child(%d) received value: %s\n", getpid(), msg2);
        printf("Child(%d) received value: %s\n", getpid(), msg3);

        // close read descriptor
        close(fd[0]);
    }

    return 0;
}
