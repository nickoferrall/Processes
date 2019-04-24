// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here

    pid_t childPid;
    childPid = fork();

    printf("In the beginning..\n");

    if (childPid == 0)
    {
        printf("Hello!\n");
        exit(0);
    }

    else if (childPid < 0)
    {
        printf("Fork failed\n");
    }

    else // main parent process after the fork succeeds
    {
        int returnStatus;
        waitpid(childPid, &returnStatus, 0); // parent waits for the child to terminate

        if (returnStatus == 0)
        {
            printf("Goddbye.\n");
        }
        if (returnStatus == 1)
        {
            printf("Child process terminated with an error.\n");
        }
    }

    return 0;
}
