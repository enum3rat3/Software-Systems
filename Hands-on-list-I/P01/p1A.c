#include<stdio.h>
#include<unistd.h>

int main()
{
	symlink("p1A", "p1ASoftLink");
	return 0;
}
