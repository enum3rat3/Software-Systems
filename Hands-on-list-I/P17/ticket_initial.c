/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a separate program, to open the file, implement write lock,
read the ticket number, increment the number and print the new ticket number
then close the file

Date: 25 Aug 2024
*/

#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>

struct database {
     int comp;
     int ticket;
} db;

int main() {
     struct flock locking;
     locking.l_type = F_WRLCK;
     locking.l_whence = SEEK_SET;
     locking.l_start = 0;
     locking.l_len = 0;

     int fd = open("ticket_count.txt", O_RDWR);
     
     if (fd == -1) {
          printf("File cannot be opened \n");
          return 0;
     }

     int stat = fcntl(fd, F_SETLK, &locking);
     
     if (stat == -1) {
          printf("Cannot obtained the lock so exiting the program \n");
          return 0;
     }

     for (int i = 0; i < 5; i++) {
          db.comp = i + 1;
          db.ticket = 120;
          write(fd, &db, sizeof(db));
     }
     locking.l_type = F_UNLCK;
     fcntl(fd, F_SETLK, &locking);

     close(fd);

     return 0;
}
