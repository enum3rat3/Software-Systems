/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to display the environmental variable of the user (use environ).
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

extern char **environ;

int main(int argc, char *argv[])
{
	printf("Environment Variables:\n");
//	printf("PWD: %s\n", getenv("PWD"));
	
	while (*environ)
	{       
		// Loop through each environment variable
        	printf("%s\n", *environ);
        	environ++;
	}

	return 0;
}
