#include<stdio.h>
#include<unistd.h>

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

        printf("This is the child process. PID: %d, Parent PID: %d\n", getpid(), getppid());
    }
    else
    {

        printf("This is the parent process. PID: %d, Child PID: %d\n", getpid(), pid);
    }
     
    return 0;
}
