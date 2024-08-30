/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Create the following types of a files using (i) shell command (ii) system call
		a. soft link (symlink system call)
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	symlink("p1A", "p1ASoftLink");
	return 0;
}
