/*
Name: Jaimin Jadvani 
Roll No. MT2024064
Program Name: Write a program to copy file1 into file2 ($cp file1 file2).
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int arg, char *argv[])
{
	if(arg != 3)
	{
		printf("Invalid Arguments\nUsage: cp file1Name file2Name\n");
	}

	// Read file
	FILE *f1 = fopen(argv[1], "r");
	if(!f1)
	{
		printf("Error in Opening the file!\n");
		return -1;
	}

	// Write file
	FILE *f2 = fopen(argv[2], "w");
	if(!f2)
	{
		printf("Error in Opening the file!\n");
		return -1;
	}

	while(fgetc(f1) != EOF)
	{
		fputc(fgetc(f1), f2);
	}
	return 0;
}
