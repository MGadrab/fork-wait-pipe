//
// Created by Mohammed Gadrab on 4/7/25.
//

#ifndef FORK_WAIT_PIPE_FIFO_H
#define FORK_WAIT_PIPE_FIFO_H
#include "pipes.h"
/// needed files for FIFO
#include <sys/stat.h>
#include <sys/types.h>
/// FIFO is like a pipe but are able to read and write from any hieracy, since pipes can only talk from parent to Child; makes a file for you
int FIFO(){
mkfifo("MyFirstFIFO", 0777); /// 0777 just tells the operating system that the FIFO can be read from and wrote to any by anyone in the system

    return 0;
};



#endif //FORK_WAIT_PIPE_FIFO_H
