// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here

    // FILE *fp;

    // fp = fopen("text.txt", "w");

    // fprintf(fp, "%s, %s\n", str1, str2);

    // fclose(fp);

    int c;
    FILE *file;
    file = fopen("text.txt", "r");
    if (file)
    {
        while ((c = getc(file)) != EOF)
            putchar(c);
        printf("\n");
        fclose(file);
    };

    pid_t pid = fork();

    if (pid == 0)
    {
        int c;
        FILE *file;
        file = fopen("text.txt", "r");
        if (file)
        {
            while ((c = getc(file)) != EOF)
                putchar(c);
            printf("\n");
            fclose(file);
        };

        FILE *f = fopen("text.txt", "w");
        if (f == NULL)
        {
            printf("Error opening file!\n");
            exit(1);
        }

        /* print some text */
        const char *text = "We're writing like a mad man";
        fprintf(f, "Some text: %s\n", text);

        /* print integers and floats */
        int i = 1;
        float py = 3.1415927;
        fprintf(f, "Integer: %d, float: %f\n", i, py);

        /* printing single chatacters */
        char my_char = 'A';
        fprintf(f, "A character: %c\n", my_char);

        fclose(f);
    }
    else
    {
        printf("Second... %d\n", getpid());
        int c;
        FILE *file;
        file = fopen("text.txt", "r");
        if (file)
        {
            while ((c = getc(file)) != EOF)
                putchar(c);
            printf("\n");
            fclose(file);
        };

        FILE *f = fopen("text.txt", "w");
        if (f == NULL)
        {
            printf("Error opening file!\n");
            exit(1);
        }

        /* print some text */
        const char *text = "We're in the second clause.. esoooo!";
        fprintf(f, "Some text: %s\n", text);

        /* print integers and floats */
        int i = 1;
        float py = 7810;
        fprintf(f, "Integer: %d, float: %f\n", i, py);

        /* printing single chatacters */
        char my_char = 'Z';
        fprintf(f, "A character: %c\n", my_char);

        fclose(f);
    }

    printf("At the end... %d\n", getpid());

    return 0;
}
