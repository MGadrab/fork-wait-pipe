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
if (id == 0){
    close(fd[0]); // since in this process we are just writing we should close in the beginning to avoid errors
    int x;
    printf("Input a number");
    scanf("%d", &x); // & returns the address of the variable
    write(fd[1], &x, sizeof(int));
    close(fd[1]);
}
else{
    int y;
    read(fd[0], &y, sizeof(int));
}
return 0;
}