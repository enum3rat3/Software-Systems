/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to perform mandatory locking.
		a. Implement write lock
		b. Implement read lock
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>

int main()
{

	int fd = open("file16.txt", O_WRONLY|O_APPEND);
	if(fd == -1)
	{
		printf("File can't be opened\n");
		exit(0);
	}

	struct flock locking;
	locking.l_type = F_WRLCK;
	locking.l_whence = SEEK_SET;
	locking.l_start = 0;
	locking.l_len = 0;

	int stat = fcntl(fd, F_SETLK, &locking);
	if(stat == -1)
	{
		printf("Can't obtained the lock for writing so exiting the program\n");
		exit(0);
	}

	char *buffer = "This to written by locking the file\n";
	write(fd, buffer, 37);

	locking.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &locking);

	close(fd);

	// Read Lock
	fd = open("file16.txt", O_RDONLY);
	locking.l_type = F_RDLCK;

	stat = fcntl(fd, F_SETLK, &locking);
	if(stat == -1)
	{
		printf("Can't obtained the lock for reading file\n");
		exit(0);
	}

	char ss[1024];

	while(read(fd, ss, 1))
	{
		printf("%s", ss);
	}

	locking.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &locking);

	close(fd);

	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P16$ touch file16.txt
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P16$ gcc p16.c -o p16
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P16$ ./p16 
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P16$ cat file16.txt 
This to written by locking the file

*/
