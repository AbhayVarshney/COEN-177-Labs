#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

// 12 child processes
// 2 or 3 child process that a process can create
int main() {
    int i = 0, status, level = 1, processes = 3;
    printf("Current Process: %d\n" , getpid());
    for (i = 0; i < processes; i++) {
        if (fork() != 0) waitpid(-1, &status, 0); /* parent */
        else {
            printf("Parent process id - [%d] Child process id - [%d]\n" , getppid(), getpid());
            level++;
//            if (i == 1 && level == 2) processes = 2;
//            else processes = 3;
            i = -1; // reset
        }
        // max height. no more children should be created
        if (level >= 3) exit(0);
    };
}