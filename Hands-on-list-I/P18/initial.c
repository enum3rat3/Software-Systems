/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to perform Record locking.
                a. Implement write lock
                b. Implement read lock
Create three records in a file. Whenever you access a particular record, first
lock it then modify/access to avoid race condition.

Date: 25 Aug 2024
*/

#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>

struct database {
     int roll;
     int marks;
} db;

int main() {
     struct flock locking;
     locking.l_type = F_WRLCK;
     locking.l_whence = SEEK_SET;
     locking.l_start = 0;
     locking.l_len = 0;

     int fd = open("record.txt", O_RDWR);
     if (fd == -1) {
          printf("File cannot be opened \n");
          return 0;
     }

     int stat = fcntl(fd, F_SETLK, &locking);
     if (stat == -1) {
          printf("Cannot obtained the lock so exiting the program \n");
          return 0;
     }

     db.roll = 1;
     db.marks = 50;
     write(fd, &db, sizeof(db));

     db.roll = 2;
     db.marks = 60;
     write(fd, &db, sizeof(db));

     db.roll = 3;
     db.marks = 70;
     write(fd, &db, sizeof(db));

     locking.l_type = F_UNLCK;
     fcntl(fd, F_SETLK, &locking);

     close(fd);

     fd = open("record.txt", O_RDONLY);
     locking.l_type = F_RDLCK;

     stat = fcntl(fd, F_SETLK, &locking);
     if (stat == -1) {
          printf(
              "Cannot obtained the lock  for reading file so exiting the "
              "program  \n");
          exit(0);
     }

     while (read(fd, &db, sizeof(db))) {
          printf("%d  %d \n", db.roll, db.marks);
     }
     locking.l_type = F_UNLCK;
     fcntl(fd, F_SETLK, &locking);

     close(fd);

     return 0;
}
