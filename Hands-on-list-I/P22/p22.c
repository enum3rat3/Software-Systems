/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.

Date: 28 Aug 2024
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main()
{
	int fd = open("file22.txt", O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	int childPID;

	// Creating child process
	if((childPID = fork()) == 0)
	{
		printf("Child process writing into...\n");
		const char *str = "This line is written by child process in file22.txt\n";
		write(fd, str, strlen(str));
		close(fd);
	}
	else
	{
		printf("Parent process writing into...\n");
		const char *str = "This line written by parent process in file22.txt\n";
		write(fd, str, strlen(str));
		close(fd);
	}

	return 0;
}

/*
Output: 

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P22$ gcc p22.c -o p22
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P22$ ./p22 
Parent process writing into...
Child process writing into...

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P22$ cat file22.txt 
This line written by parent process in file22.txt
This line is written by child process in file22.txt
*/
