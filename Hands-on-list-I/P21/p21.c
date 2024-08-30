/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program, call fork and print the parent and child process id.
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Parent Process ID: %d\n", getpid());
	int childId = fork();
	if(childId)
	{
		printf("Child Process ID: %d\n", childId);
	}
	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P21$ ./p21
Parent Process ID: 4360
Child Process ID: 4361

*/
