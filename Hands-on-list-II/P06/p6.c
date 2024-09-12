/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Description: Write a simple program to create three threads.

Date: 11 Sept 2024
*/

#include<stdio.h>
#include<pthread.h>

void myFunc(void *threadNum)
{
	int *num = (int *) threadNum;
	printf("Thread %d created\n", *num);
}

int main()
{
	pthread_t t;
	void *r;
	
	for(int i = 1; i <= 3; i++)
	{
		int x = pthread_create(&t, NULL, (void *)myFunc, &i);
		if(x != 0)
		{
			printf("Error in creating thread %d\n", i);
		}
		pthread_join(t, &r);
	}

	return 0;
}


/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-II/P06$ gcc -pthread p6.c -o p6

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-II/P06$ ./p6 
Thread 1 created
Thread 2 created
Thread 3 created

*/
