/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to print the following information about a given file.
		a. inode
		b. number of hard links
		c. uid
		d. gid
		e. size
		f. block size
		g. number of blocks
		h. time of last access
		i. time of last modification
		j. time of last change

Date: 18 Aug 2024
*/

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>
int main(int agrv,char *argc[]){
	struct stat s;

	stat(argc[1],&s);
	
	printf("id of device=%ld\n",s.st_dev);
	
	printf("inode=%ld\n",s.st_ino);
	
	printf("file type and mode=%d\n",s.st_mode);
	
	printf("number of hardlink=%ld\n",s.st_nlink);
	
	printf("user id=%d\n",s.st_uid);
	
	printf("group id=%d\n",s.st_gid);
	
	printf("device id=%ld\n",s.st_rdev);
	
	printf("total size in bytes=%ld\n",s.st_size);
	
	printf("Block size of filesystem=%ld\n",s.st_blksize);
	
	printf("Number of block=%ld\n",s.st_blocks);
	
	printf("Last access time=%s",ctime(&(s.st_atim).tv_sec));
	
	printf("Last modified time=%s",ctime(&(s.st_mtim).tv_sec));
	
	printf("Last status change time=%s",ctime(&(s.st_ctim).tv_sec));
	
	return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P09$ ./p9 ../P10
id of device=2053
inode=1838032
file type and mode=16893
number of hardlink=2
user id=1000
group id=1000
device id=0
total size in bytes=4096
Block size of filesystem=4096
Number of block=8
Last access time=Thu Aug 29 08:18:52 2024
Last modified time=Wed Aug 21 22:39:13 2024
Last status change time=Wed Aug 21 22:39:13 2024


*/
