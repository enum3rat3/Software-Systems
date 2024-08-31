/*
Name: Jaimin Jadvani 
Roll No.:  MT2024064
Program Name: Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
	a. use dup
	b. use dup2
	c. use fcntl

Date: 18 Aug 2024
*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argv,char *argc[]){

	int fd=open(argc[1],O_WRONLY|O_APPEND|O_CREAT,S_IRWXU);
	int d1=dup(fd);
	write(fd,"Hi, written using original file descriptor\n",50);
	write(d1,"Hi, USER Written using dup() file descriptor\n",51);
	
	int d2=dup2(fd,10);
	write(d2,"Hi, USER written using dup2() file descriptor\n", 52);
	
	int d3 = fcntl(fd, F_DUPFD, 5); 
	write(d3,"Hi, USER written using fcntl() file descriptor\n",53);
	
	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P11$ ./p11 file1.txt
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P11$ cat file1.txt
Hi, written using original file descriptor
Hi, USER Written using dup() file descriptor
Hi, USER written using dup2() file descriptor
Hi, USER written using fcntl() file descriptor
Hi, written using original file descriptor
HiHi, USER Written using dup() file descriptor
Hi,Hi, USER written using dup2() file descriptor
Hi, Hi, USER written using fcntl() file descriptor


*/
