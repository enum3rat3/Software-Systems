/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to execute an executable program.
		a. use some executable program
		b. pass some input to an executable program. (for example execute an executable of $./a.out name) 

Date: 28 Aug 2024
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	char *execPath = "../P15/p15";
	char *arg = "p15.c";

	printf("-------- Executing %s program using execl() ---------\n", execPath);
	execl(execPath, execPath, arg, NULL);
	
	return 0;
}


/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P26$ gcc p26.c -o p26
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P26$ ./p26 
-------- Executing ../P15/p15 program using execl() ---------
Environment Variables:
SHELL=/bin/bash
SESSION_MANAGER=local/Ubuntu-VM:@/tmp/.ICE-unix/1510,unix/Ubuntu-VM:/tmp/.ICE-unix/1510
QT_ACCESSIBILITY=1
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
XDG_MENU_PREFIX=gnome-
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
LANGUAGE=en_IN:en
GNOME_SHELL_SESSION_MODE=ubuntu
SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
XMODIFIERS=@im=ibus
DESKTOP_SESSION=ubuntu
SSH_AGENT_PID=1471
GTK_MODULES=gail:atk-bridge
PWD=/home/jaimin/Desktop/Software-Systems/Hands-on-list-I/P26



*/
