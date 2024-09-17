/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Description: Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.

Date: 17 Sept 2024
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{		
    // Creating child process
    if(fork() == 0)
    {
        printf("Child Process Created...\n");
        sleep(5);


        // Getting parent id
        int parentPID = getppid();
        
        // Sending SIGKILL signal to parent
        kill(parentPID, SIGKILL);
        printf("Parent process killed\n");


        sleep(4);
        printf("Child is orphan now...\n");    
        printf("New parent id: %d\n", getppid());
    }
    else
    {
        printf("Hello from Parent Process and my pid: %d\n", getpid());
        for(;;);
    }

	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-II/P12$ gcc p12.c -o p12
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-II/P12$ ./p12 
Hello from Parent Process and my pid: 6081
Child Process Created...
Parent process killed
Killed
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-II/P12$ Child is orphan now...
New parent id: 3895

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-II/P12$ ps -aux | grep 3895
jaimin      3895  0.0  0.1  19800 10496 ?        Ss   18:56   0:00 /lib/systemd/systemd --user


*/

