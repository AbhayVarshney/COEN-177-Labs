#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
    int i, status, processes = 8;
    printf("Current Process: %d\n" , getpid());
    for (i = 0; i < processes; i++) {
        if (fork() != 0) {
            // wait for process termination/change state
            waitpid(-1, &status, 0); /* parent */
            exit(0);
        } else printf("Parent process id - [%d] Child process id - [%d]\n" , getppid(), getpid());
    };
}
