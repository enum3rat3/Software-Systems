/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to find out time taken to execute getpid system call. Use time stamp counter.

Date: 28 Aug 2024
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
// #include<x86intrin.h>

int main()
{
	int pid;
	struct timeval startTime, endTime;

	gettimeofday(&startTime, NULL);
	pid = getpid();
	gettimeofday(&endTime, NULL);

	printf("Time taken to execute getpid() system call: %ld\n", (endTime.tv_sec- startTime.tv_sec));

	return 0;
}
