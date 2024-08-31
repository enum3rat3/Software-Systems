/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to execute ls -Rl by the following system calls
	      a. execl

Date: 28 Aug 2024
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("execl() system call:\n");
	execl("/bin/ls", "-Rl", "/home/jaimin/Desktop/Software-Systems/Hands-on-list-I/P27/", NULL);
	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P27$ gcc p27a.c -o p27a
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P27$ ./p27a
execl() system call:
p27a  p27a.c  p27b.c  p27c.c  p27d.c  p27e.c

*/
