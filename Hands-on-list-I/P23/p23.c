/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to create a Zombie state of the running program.
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    int fd;
    fd = fork();
    if (fd == 0)
    {
        printf("Child pid= %d\n", getpid());
        printf("Parent id= %d\n", getppid());
    }
    else
    {
        sleep(300);
        printf("Inside parent pid= %d\n", getpid());
        printf("Child pid= %d\n", fd);
    }
    return 0;
}

/*
Output:

Name:	p23
State:	Z (zombie)
Tgid:	5935
Ngid:	0
Pid:	5935
PPid:	5934


*/
