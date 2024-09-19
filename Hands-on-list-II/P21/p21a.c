/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Description: Write two programs so that both can communicate by FIFO - Use two way communications

Date: 19 Sept 2024
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{	
    int fifoStatus;                              
    char data[] = "Hello from 20a.c program to 20b.c";
    int fileDescriptor;                         
    char *fifoFile = "./FIFO_File";               
    int writeBytes;

    fifoStatus = mkfifo(fifoFile, S_IRWXU);

    if (fifoStatus == -1)
        perror("Error: \n");
    fileDescriptor = open(fifoFile, O_WRONLY);
    if (fileDescriptor == -1)
        perror("Error: \n");
    else
    {
        writeBytes = write(fileDescriptor, &data, sizeof(data));
        if (writeBytes == -1)
            perror("Error: \n");
        close(fileDescriptor);
    }
}

/*

*/