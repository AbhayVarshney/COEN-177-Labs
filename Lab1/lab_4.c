/**
 *
 */
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

// 17 child processes
// 2 or 3 child process that a process can create
int main() {
    int i = 0, status, level = 1, processes = 2;
    printf("Current Process: %d\n" , getpid());
    for (i = 0; i < processes; i++) {
        if (fork() != 0) {
            waitpid(-1, &status, 0); /* parent */
        } else {
            printf("Parent process id - [%d] Child process id - [%d]\n" , getpid(), getppid());
            level++;
            if (level == 2 && i == 0) processes = 3;
            else processes = 2;
            i = -1; // reset
        }

        // max height. no more children should be created
        if (level >= 4) exit(0);
    };
}

