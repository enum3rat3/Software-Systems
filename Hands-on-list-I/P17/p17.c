/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to simulate online ticket reservation. Implement write lock. 
Write a program to open a file, store a ticket number and exit. Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file. 

Date: 25 Aug 2024
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>

struct database
{
	int comp;
	int ticket;
}db;

struct passenger
{
 	 char name[100];
	 int comp;
	 int ticket;
}p1;

int main()
{
	  struct flock locking;
	  locking.l_type = F_RDLCK;
	  locking.l_whence = SEEK_SET;
	  locking.l_start = 0;
	  locking.l_len = 0;
	
	  printf("Please enter your name : ");
	  scanf("%s",p1.name);
	  printf("Please enter your required compartment : ");
	  scanf("%d",&(p1.comp));

	  int fd = open("ticket_count.txt",O_RDWR);
	  if(fd == -1)
	  {
		    printf("File cannot be opened \n");
		    exit(0);
	  }

	  int stat = fcntl(fd,F_SETLK,&locking);
	  if(stat == -1)
	  {
		    printf("Cannot obtained the lock so exiting the program \n");
		    exit(0);
	  }

	  lseek(fd,sizeof(db)*(p1.comp-1),SEEK_SET);
	  read(fd,&db,sizeof(db));
	  locking.l_type = F_UNLCK;
	  fcntl(fd,F_SETLK,&locking);

	  printf("%d  %d \n",db.comp,db.ticket);

	  close(fd);
	
	  fd = open("ticket_details.txt",O_RDWR|O_APPEND);

	  if(fd == -1)
 	  {
		    printf("File cannot be opened \n");
		    exit(0);
	  }


	  locking.l_type = F_WRLCK;
	  fcntl(fd,F_SETLK,&locking);
	  p1.ticket = db.ticket+1;
 	  lseek(fd,0,SEEK_CUR);
	  write(fd,&p1,sizeof(p1));

	  locking.l_type = F_UNLCK;
	  fcntl(fd,F_SETLK,&locking);

	  close(fd);

	  fd = open("ticket_count.txt",O_RDWR);
	  if(fd == -1)
  	  {
		    printf("File cannot be opened \n");
		    exit(0);
 	  }

	  locking.l_type = F_WRLCK;
	  stat = fcntl(fd,F_SETLK,&locking);

	  if(stat == -1)
	  {
		    printf("Cannot obtained the lock so exiting the program \n");
		    exit(0);
 	  }

	  lseek(fd,sizeof(db)*(p1.comp-1),SEEK_SET);

	  db.ticket = db.ticket+1;
	  write(fd,&db,sizeof(db));
	  locking.l_type = F_UNLCK;
	  fcntl(fd,F_SETLK,&locking);

	  close(fd);

	  return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P17$ ./ticket_initial
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P17$ ./testing
1  --> 120
2  --> 120
3  --> 120
4  --> 120
5  --> 120
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P17$ vim p17.c
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P17$ gcc p17.c -o p17
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P17$ ./p17
Please enter your name : jaimin
Please enter your required compartment : 3
3  120
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P17$ ./testing
1  --> 120
2  --> 120
3  --> 121
4  --> 120
5  --> 120
jaimin    3   121

*/
