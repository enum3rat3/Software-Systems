/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).

Date: 28 Aug 2024
*/

#include<stdio.h>
#include<sched.h>
#include<unistd.h>

int main()
{
	    	int currentPolicy, pid;
		pid = getpid();
    		currentPolicy = sched_getscheduler(pid);
    		struct sched_param priority;
    
		priority.sched_priority = 10;

    		switch (currentPolicy)
    		{
		    case SCHED_FIFO:
			        printf("Current policy is FIFO\n");
			        sched_setscheduler(pid, SCHED_RR, &priority);
			        currentPolicy = sched_getscheduler(pid);
			        printf("Current policy is %d\n", currentPolicy);
			        break;
		    
		    case SCHED_RR:
			        printf("Current policy is RR\n");
			        sched_setscheduler(pid, SCHED_FIFO, &priority);
			        currentPolicy = sched_getscheduler(pid);
			        printf("Current policy is %d\n", currentPolicy);
			        break;

		    case SCHED_OTHER:
			        printf("Current policy is OTHER\n");
			        sched_setscheduler(pid, SCHED_FIFO, &priority);
			        currentPolicy = sched_getscheduler(pid);
			        printf("Current policy is %d\n", currentPolicy);
			        break;
		    default:
			        perror("Error while getting current policy\n");
	    	}	
		return 0; 
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P29$ sudo ./p29 
[sudo] password for jaimin: 
Current policy is OTHER
Current policy is 1
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P29$ ./p29 
Current policy is OTHER
Current policy is 0

*/
