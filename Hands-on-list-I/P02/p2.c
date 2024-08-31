/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory.

Date: 18 Aug 2024
*/

#include<stdio.h>

int main()
{
	for(;;){

	}
	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P02$ cat /proc/6357/status
Name:	p2
Umask:	0002
State:	R (running)
Tgid:	6357
Ngid:	0
Pid:	6357
PPid:	3413
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 120 132 133 1000
NStgid:	6357
NSpid:	6357
NSpgid:	6357
NSsid:	3413


*/
