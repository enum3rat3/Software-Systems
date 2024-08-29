/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Find out the priority of your running program. Modify the priority with nice command.
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
	int processPID = getpid();
	int priority = getpriority(PRIO_PROCESS, processPID);

	printf("Current priority of process: %d\n", priority);

	int newPriority = nice(6);

	printf("updated priority of process: %d\n", newPriority);
	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P20$ gcc p20.c -o p20
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P20$ ./p20

Current priority of process: 0
updated priority of process: 6

*/
