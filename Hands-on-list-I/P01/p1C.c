/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: FIFO (mkfifo Library Function or mknod system call)

Date: 18 Aug 2024
*/

#include<stdio.h>
#include<sys/stat.h>

int main(int argc,char *argv[]){
	
	int i = mkfifo(argv[1],S_IRWXU);
	
	if(i == 0)
	{
		printf("FIFO file created\n");
	}
	
	return 0;
}
