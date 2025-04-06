
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
    int TotalVal;
    int fd[2];
    if (pipe(fd) < 0){ /// signifies error in the pipe
        return 1;
    }
    int id = fork();
    if(id < 0){ /// error in the fork
        return 2;
    }
    if(id == 0){ /// id 0 means that it is a child
        start = 0;
        end = arrSize/2; /// the end is the middle array, dont need to add 'start' as start is 0
    }
    else{
        start = arrSize/2; /// start where the child ends
        end = arrSize;
    }
    int value = 0;
    for(int i = start;i < end; i++){ /// you can have this outside the if/else cause the loop is the same for both

        value+= arr[i];
    }
    printf("value: %d\n", value);

    /// now that we have value for each we need to use pipe to send values
    if(id == 0){ /// write in child
        close(fd[0]);
        write(fd[1], &value, sizeof(value));
        close(fd[1]);
    }
    else{
        wait(NULL);
        int ValueFromChild;
        close(fd[1]);
        read(fd[0], &ValueFromChild, sizeof(ValueFromChild));
        close(fd[0]);
        TotalVal = value + ValueFromChild;
        printf("Total Value: %d", TotalVal);
         /// parent needs to wait for child or ELSE!! (if parent goes first cannot add value of child)
    }
    return 0;
}
/*
 a mistake I was doing while trying this is that I used pipe AFTER fork.
 have to use it BEFORE so that all processes share the same pipe file descriptor
*/
#endif //FORK_WAIT_PIPE_USAGE_OF_PIPES_FORKS_H
