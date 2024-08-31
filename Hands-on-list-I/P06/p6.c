/*
Name: Jaimin Jadvani
Roll No.: MT2024064
Program Name: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

Date: 18 Aug 2024
*/

#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 1000

int main() {
    char buffer[BUFFER_SIZE]; 
    ssize_t bytesRead;

    
    while ((bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, bytesRead) != bytesRead) {
            write(STDERR_FILENO, "Error!\n", 12);
            return 1;
        }
    }

    if (bytesRead < 0) {
        write(STDERR_FILENO, "Error!\n", 11);
        return 1;
    }

    return 0;
}

/*
Output:

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-I/P06$ ./p6
Hello, My name is Jaimin Jadvani
Hello, My name is Jaimin Jadvani


I'm 1st year MTech CSE student
I'm 1st year MTech CSE student

*/
