/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Create the following types of a files using (i) shell command (ii) system call
		b. hard link (link system call)
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	link("p1B", "hardlinkSystemCall");
	return 0;
}
