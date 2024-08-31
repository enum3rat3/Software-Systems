/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.

Date: 18 Aug 2024
*/

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv)
{

	int fp1 = creat("file1", S_IRWXU);
	int fp2 = creat("file2", S_IRWXU);
	int fp3 = creat("file3", S_IRWXU);
	int fp4 = creat("file4", S_IRWXU);
	int fp5 = creat("file5", S_IRWXU);
	
	for(;;)
	{}

	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P05$ ./p5 &
[1] 6519
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P05$ cat /proc/6519/fd/
0  1  2  3  4  5  6  7

*/
