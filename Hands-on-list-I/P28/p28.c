/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to get maximum and minimum real time priority
*/

#include<stdio.h>
#include<sched.h>

int main()
{

	printf("--------- For FIFO scheduling ----------\n");
	int maxPriority = sched_get_priority_max(SCHED_FIFO);
	printf("Max priority: %d\n", maxPriority);

	int minPriority = sched_get_priority_min(SCHED_FIFO);
	printf("Min priority: %d\n", minPriority);


	printf("--------- For Round Robin scheduling ----------\n");
	maxPriority = sched_get_priority_max(SCHED_RR);
	printf("Max priority: %d\n", maxPriority);

	minPriority = sched_get_priority_min(SCHED_RR);
	printf("Min priority: %d\n", minPriority);

	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P28$ gcc p28.c -o p28
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P28$ ./p28
--------- For FIFO scheduling ----------
Max priority: 99
Min priority: 1
--------- For Round Robin scheduling ----------
Max priority: 99
Min priority: 1


*/
