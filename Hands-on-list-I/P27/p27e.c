/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to execute ls -Rl by the following system calls
	      e. execvp
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	char *arg[] = {"/bin/ls", "-Rl", "/home/jaimin/Desktop/Software-Systems/Hands-on-list-I/P07/", NULL};
	printf("execvp() system call:\n");
	execvp(arg[0], arg);

	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P27$ gcc p27e.c -o p27e
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P27$ ./p27e
execvp() system call:
/home/jaimin/Desktop/Software-Systems/Hands-on-list-I/P07/:
total 32
-rwxrwxr-x 1 jaimin jaimin 16824 Aug  9 18:58 cp
-rw-rw-r-- 1 jaimin jaimin    56 Aug  9 18:10 file1
-rw-rw-r-- 1 jaimin jaimin    28 Aug  9 18:58 file2
-rw-rw-r-- 1 jaimin jaimin   602 Aug 21 22:37 p7.c

*/
