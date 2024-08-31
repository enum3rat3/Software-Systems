/*
Name: Jaimin Jadvani 
Roll No.: MT2024064
Program Name: Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
	      bytes (use lseek) and write again 10 bytes.
		a. check the return value of lseek
		b. open the file with od and check the empty spaces in between the data.

Date: 18 Aug 2024
*/

#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
	int fd = open("file1.txt", O_RDWR);
	
	char temp[11] = "ABCDEFGHIJ", buffer[11];

	// writing 10 bytes
	write(fd, temp, 10);

	// moving read/write pointer by 10 bytes;
	int val = lseek(fd, 10, SEEK_CUR);

	char temp1[11] = "KLMNOPQRS\n";
	
	//Again writing 10 bytes
	write(fd, temp1, 10);
	
	printf("Value lseek() returned: %d\n", val);
	close(fd);	
	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P10$ ./p10 file1.txt
Value lseek() returned: 20
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P10$ cat file1.txt
ABCDEFGHIJKLMNOPQRS

*/
