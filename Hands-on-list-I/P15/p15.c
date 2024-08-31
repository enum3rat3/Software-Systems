/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to display the environmental variable of the user (use environ).

Date: 18 Aug 2024
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

extern char **environ;

int main(int argc, char *argv[])
{
	printf("Environment Variables:\n");
//	printf("PWD: %s\n", getenv("PWD"));
	
	while (*environ)
	{       
		// Loop through each environment variable
        	printf("%s\n", *environ);
        	environ++;
	}

	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P15$ ./p15 
Environment Variables:
SHELL=/bin/bash
SESSION_MANAGER=local/Ubuntu-VM:@/tmp/.ICE-unix/1474,unix/Ubuntu-VM:/tmp/.ICE-unix/1474
QT_ACCESSIBILITY=1
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
XDG_MENU_PREFIX=gnome-
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
LANGUAGE=en_IN:en
GNOME_SHELL_SESSION_MODE=ubuntu

*/
