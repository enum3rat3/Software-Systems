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
