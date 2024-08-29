/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Title:  write a program to create a file and print the file descriptor value. Use creat ( ) system call
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	char *fname = "newfile.txt";
	int filedesc = creat(fname, O_CREAT|S_IRWXU);

	printf("Value of file descriptor: %d\n", filedesc);
	return 0; 
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P03$ ./p3
Value of file descriptor: 3

*/
