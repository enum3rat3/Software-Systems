/*
Name : Jaimin Jadvani
Roll No.: MT2024064
Program Name : Write a program to run a script at a specific time using a Daemon process.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    pid_t pid = 0;
    pid_t sid = 0;
    int fd = open("file30.txt",O_WRONLY);
    pid = fork();
    if(pid < 0)
    {
        perror("Failed to create child process!\n");
        exit(1);
    }
    
    if(pid > 0)
    {
        printf("The process id of the parent is %d\n",pid);
        exit(0);
    }
    
    sleep(5);
    
    umask(0);
    
    sid = setsid();
    
    if(sid < 0)
    {
        exit(0);
    }
    
    chdir("/home/jaimin/Desktop/Software-Systems/Hands-on-list-I/P30/");
    close(0);
    close(1);
    close(2);
    
    while(1)
    {
        sleep(2);
        write(fd,"this is deamon\n",15);
    }
    
    return 0;    
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P30$ touch file30.txt
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P30$ ./p30
The process id of the parent is 7628
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P30$ cat file30.txt
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P30$ cat file30.txt
this is deamon
this is deamon
this is deamon
this is deamon
this is deamon

*/
