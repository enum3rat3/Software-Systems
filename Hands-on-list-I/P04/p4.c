/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to open an existing file with read write mode. Try O_EXCL flag also.
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argv,char *argc[])
{
	if(argv != 2)
	{
		printf("Usage: ./p4 <filename>\n");
		return -1;
	}
	int i = open(argc[1], O_RDWR);
	printf("%d\n",i);
	
	int j = open(argc[1], O_EXCL);
	printf("%d\n",j);

	return 0;
}
