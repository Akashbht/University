 
#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
int main()
{
printf("Executing... ");
execlp("ls","ls","-l",NULL);
return 0;
}
