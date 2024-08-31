/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to open a file, store a ticket number and exit

Date: 25 Aug 2024
*/

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

struct database {
     int comp;
     int ticket;
} db;

struct passenger {
     char name[100];
     int comp;
     int ticket;
} p1;

int main() {
     int fd = open("ticket_count.txt", O_CREAT, S_IRWXU);
     struct database as;
     while (read(fd, &as, sizeof(as))) {
          printf("%d  --> %d \n", as.comp, as.ticket);
     }

     fd = open("ticket_details.txt", O_CREAT, S_IRWXU);

     while (read(fd, &p1, sizeof(p1))) {
          printf("%s    %d   %d \n", p1.name, p1.comp, p1.ticket);
     }

     return 0;
}
