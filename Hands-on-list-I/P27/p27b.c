/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to execute ls -Rl by the following system calls
       	      b. execlp

Date: 28 Aug 2024
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("execlp() system call:\n");
	execl("/bin/ls", "-Rl", "/home/jaimin/Desktop/Software-Systems/Hands-on-list-I/P21/", NULL);
	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P27$ gcc p27b.c -o p27b
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P27$ ./p27b
execlp() system call:
p21  p21.c

*/
