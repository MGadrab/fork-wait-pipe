#include <iostream>
#include <unistd.h>

int main(int argc, char* argv[]){
int fd[2];// pipes have two ends
// fd[0] = read
// fd[1] = write
if (pipe(fd)== -1){
    printf("error opening pipe\n");
    return 1;
}
int id = fork();


}