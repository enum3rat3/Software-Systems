/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to find out the opening mode of a file. Use fcntl
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void print_file_mode(int flags) {
    printf("File mode:\n");

    if (flags & O_RDONLY) {
        printf("  Read-only\n");
    }
    else if (flags & O_WRONLY) {
        printf("  Write-only\n");
    }
    else if (flags & O_RDWR) {
        printf("  Read/Write\n");
    }
    else if (flags & O_APPEND) {
        printf("  Append mode\n");
    }
    else if (flags & O_CREAT) {
        printf("  Created if not exists\n");
    }
    else if (flags & O_TRUNC) {
        printf("  Truncate file to zero length\n");
    }
    else if (flags & O_EXCL) {
        printf("  Exclusive creation\n");
    }
    else if (flags & O_NONBLOCK) {
        printf("  Non-blocking mode\n");
    }
    else if (flags & O_SYNC) {
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

    int flags = fcntl(fd, F_GETFL);

    print_file_mode(flags);

    close(fd);
    return 0;
}
