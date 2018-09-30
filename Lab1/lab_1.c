#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main() {
    char input[255];
    int status;			// status from waitpid

    while(1) {
        printf("\nInput command: ");
        scanf("%s", input);
        if(strcmp(input , "exit" ) == 0) {
            printf("Exiting program.\n\n");
            exit(0);
        } else { // not exit
            printf("Running processes.\n"); /*Execute the next instruction following the fork() system call*/
            if (fork() != 0) {
                // wait for process termination/change state
                waitpid(-1, &status, 0); /* parent */
            } else {
                execve(input, NULL, NULL); /* child process */
                printf("Could not locate program - [%s]\n", input);
                exit(0);
            }
        }
    }
}