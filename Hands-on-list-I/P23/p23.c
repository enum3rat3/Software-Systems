/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to create a Zombie state of the running program.

Date: 28 Aug 2024
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

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P23$ ./p23
Child pid= 4251
Parent id= 4250


jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P23$ cat /proc/4251/status
Name:	p23
State:	Z (zombie)
Tgid:	4251
Ngid:	0
Pid:	4251
PPid:	4250
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000

*/
