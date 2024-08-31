/*
Name: Jaimin Jadvani
Roll No. MT2024064
Program Name: Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.

Date: 18 Aug 2024
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 200

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Invalid argument, Usage: ./p8 fileName");
		return -1;
	}
	FILE *fp = fopen(argv[1], "r");
	if(!fp)
	{
		printf("Error opening the file!\n");
		return -1;
	}

	char BUF[MAX];

	while(fgets(BUF, MAX, fp))
	{
		printf("%s", BUF);
	}

	// closing the file
	fclose(fp);

	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P08$ ./p8 file1
Hello,
This program reads from file print in the terminal
Hope it will work properly.


*/
