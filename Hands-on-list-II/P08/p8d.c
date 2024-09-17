/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Description:  Write a separate program using signal system call to catch the following signals.
			d.SIGALRM (use alarm system call)

Date: 16 Sept 2024
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sigHandler(int sig)
{
	printf("SIGALRM: alarm() function expires!\n");
    exit(-1);
}

int main()
{
	if(signal(SIGALRM, sigHandler) == SIG_ERR)
	{
		printf("Error!\n");
	}

    alarm(5);

    while(1)
    {
        printf("Inside Loop\n");
        sleep(1);
    }
    
	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-II/P08$ gcc p8d.c -o p8d
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-II/P08$ ./p8d
Inside Loop
Inside Loop
Inside Loop
Inside Loop
Inside Loop
SIGALRM: alarm() function expires!


*/
