#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    if (pid < 0)
    {

        perror("Fork failed");
        return 1;
    }
    else if (pid == 0)
    {

        printf("Child process:\n");
        printf("  PID: %d\n", getpid());
        printf("  Parent PID: %d\n", getppid());
    }
    else
    {

        printf("Parent process:\n");
        printf("  PID: %d\n", getpid());
        printf("  Child PID: %d\n", pid);
    }

    return 0;
}
