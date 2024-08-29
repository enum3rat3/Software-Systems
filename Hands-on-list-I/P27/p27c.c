/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to execute ls -Rl by the following system calls
              c. execle
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("execle() system call:\n");
	execle("/bin/ls", "-Rl", "/home/jaimin/Desktop/Software-Systems/Hands-on-list-I/P20/", NULL, NULL);

	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P27$ gcc p27c.c -o p27c
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P27$ ./p27c
execle() system call:
p20  p20.c

*/
