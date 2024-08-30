/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to find out the opening mode of a file. Use fcntl
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void print_file_mode(int flag) {
     
    int mask = flag & O_ACCMODE;
	
    printf("File mode: ");

    if (mask == O_RDONLY) {
        printf("  Read-only\n");
    }
    
    else if (mask == O_WRONLY) {
        printf("  Write-only\n");
    }
    
    else if (mask == O_RDWR) {
        printf("  Read/Write\n");
    }
    else if (mask == O_APPEND) {
        printf("  Append mode\n");
    }
    else if (mask == O_CREAT) {
        printf("  Created if not exists\n");
    }
    else if (mask == O_TRUNC) {
        printf("  Truncate file to zero length\n");
    }
    else if (mask == O_EXCL) {
        printf("  Exclusive creation\n");
    }
    else if (mask == O_NONBLOCK) {
        printf("  Non-blocking mode\n");
    }
    else if (mask == O_SYNC) {
        printf("  Synchronized I/O\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./p12 filename\n");
        return -1;
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);

    if (fd < 0) {
        printf("Error in opening file!\n");
        return -1;
    }

    int flag = fcntl(fd, F_GETFL);
    // printf("%o\n", flag);

    print_file_mode(flag);

    close(fd);
    return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P12$ gcc p12.c -o p12
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P12$ ./p12 file1.txt
File mode:   Read-only

If we want other mode then write:  open(filename, <MODE>)

following <MODE> are possible:
O_RDONLY
O_WRONLY
O_RDWR
O_CREAT
O_TRUNC
O_APPEND

*/
