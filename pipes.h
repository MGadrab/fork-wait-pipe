//
// Created by Mohammed Gadrab on 4/6/25.
//
#include "usage_of_pipes_forks.h"
#ifndef FORK_WAIT_PIPE_PIPES_H
#define FORK_WAIT_PIPE_PIPES_H

int Example_pipes() {
    int fd[2];// pipes have two ends
// fd[0] = read
// fd[1] = write
    if (pipe(fd) <
        0) { // always put an error statement with these just incase something happens and you know where error is
        printf("error opening pipe\n");
        return 1;
    }
    int id = fork();//It duplicates the parent process's memory, including code, data, heap, and stack
//The child process starts its execution from the instruction immediately following the fork() call.
    if (id < 0) {
        printf(" an error forking");
        return 1;
    }
    if (id == 0) {
        close(fd[0]); // since in this process we are just writing we should close in the beginning to avoid errors
        int x;
        printf("Input a number");
        scanf("%d", &x); // & returns the address of the variable
        if (write(fd[1], &x, sizeof(int)) < 0) {
            printf("error writing\n");
            return 2;
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int y;
        read(fd[0], &y, sizeof(int));
        if (printf("got from child process before manipulation: %d\n", y) < 0) {
            printf("error occurred reading pipe before manipulation\n");
            return 3;
        }
        y = y * 5;
        close(fd[0]);
        if (printf("got from child process after manipulation: %d\n", y) < 0) {
            printf("error occurred reading pipe after manipulation\n");
            return 4;
        }
    }
}
#endif //FORK_WAIT_PIPE_PIPES_H
