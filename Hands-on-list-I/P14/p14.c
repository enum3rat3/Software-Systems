/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to find the type of a file.
		a. Input should be taken from command line.
		b. program should be able to identify any type of a file.
*/

#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Invalid argument!\nUsage: ./p14.c fileName\n");
		return -1;
	}

	struct stat fileName;
	
	if(-1 == stat(argv[1], &fileName))
	{
		printf("Invalid File Name!\n");
		return -1;
	}

	printf("File type of %s:", argv[1]);
	
	// printf("%o\n", fileName.st_mode);
	// printf("%o\n", S_IFMT);

	switch(fileName.st_mode & S_IFMT)
	{
		case S_IFLNK:
			printf(" Symbolic link\n");
			break;
		case S_IFBLK:
			printf(" Block Device\n");
			break;
		case S_IFREG:
			printf(" Regular file\n");
			break;
		case S_IFDIR:
			printf(" Directory file\n");
			break;
		case S_IFCHR:
			printf(" Character Device\n");
			break;
		case S_IFIFO:
			printf(" FIFO\n");
			break;
	}
	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P14$ ./p14 /
File type of /: Directory file
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P14$ ./p14 p14
File type of p14: Regular file

*/
