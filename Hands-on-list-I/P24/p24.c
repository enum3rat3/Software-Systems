/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to create an orphan process.
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
	int p;
	p = fork();
	if(p==0)
	{
	    sleep(5);
            printf("I am child having PID %d\n",getpid());
	    printf("My parent PID is %d\n",getppid());
     	}
	else
     	{
            printf("I am parent having PID %d\n",getpid());
	    printf("My child PID is %d\n",p);
   	} 
	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P24$ vim p24.c
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P24$ gcc p24.c -o p24
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P24$ ./p24
I am parent having PID 6674
My child PID is 6675
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P24$ I am child having PID 6675
My parent PID is 1368
*/
