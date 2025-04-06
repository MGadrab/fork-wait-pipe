
#ifndef FORK_WAIT_PIPE_USAGE_OF_PIPES_FORKS_H
#define FORK_WAIT_PIPE_USAGE_OF_PIPES_FORKS_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int pipes_and_forks(){
    int arr[]= {1,3 ,4, 5,2,3};
    int arrSize = sizeof(arr)/ sizeof(int); /// have to divide by size of int b/c sizeof returns bytes

    int start, end;
    int value;
    int fd[2];
    int id = fork();
    if (pipe(fd) < 0){ /// signifies error in the pipe
        return 1;
    }
    if(id < 0){ /// error in the fork
        return 2;
    }
    if(id == 0){ /// id 0 means that it is a child
        start = 0;
        end = start + arrSize/2; /// the end is the middle array, dont need to add 'start' as start is 0
        for(int i = start;i < end; i++){
            value = value + arr[i];
        }
        printf("value; %d\n", value);
    }
    else{
        start = arrSize/2; /// start where the child ends
        end = arrSize;
        for(int i = start;i < end; i++){
            value = value + arr[i];
        }
        printf("value; %d\n", value);
    }
    return 0;
}
#endif //FORK_WAIT_PIPE_USAGE_OF_PIPES_FORKS_H
