/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to execute ls -Rl by the following system calls
	      d. execv
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	char *arg[] = {"/bin/ls", "-Rl", "/home/jaimin/Desktop/Software-Systems/Hands-on-list-I/P27/", NULL};

	printf("execv() system call:\n");
	execv(arg[0], arg);

	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P27$ gcc p27d.c -o p27d
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P27$ ./p27d
execv() system call:
/home/jaimin/Desktop/Software-Systems/Hands-on-list-I/P27/:
total 100
-rwxrwxr-x 1 jaimin jaimin 16736 Aug 29 17:52 p27a
-rw-rw-r-- 1 jaimin jaimin   574 Aug 29 17:53 p27a.c
-rwxrwxr-x 1 jaimin jaimin 16736 Aug 29 17:54 p27b
-rw-rw-r-- 1 jaimin jaimin   550 Aug 29 17:55 p27b.c
-rwxrwxr-x 1 jaimin jaimin 16736 Aug 29 17:56 p27c
-rw-rw-r-- 1 jaimin jaimin   558 Aug 29 17:56 p27c.c
-rwxrwxr-x 1 jaimin jaimin 16792 Aug 29 18:00 p27d
-rw-rw-r-- 1 jaimin jaimin   367 Aug 29 18:00 p27d.c
-rw-rw-r-- 1 jaimin jaimin   873 Aug 29 17:51 p27e.c

*/
