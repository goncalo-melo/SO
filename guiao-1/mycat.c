#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 1024

// --- mycat ---

int main(){

    int fd_read = 0; //STDIN_FILENO
    int fd_write = 1; //STDOUT_FILENO

    char buf[BUF_SIZE];
    int bytes_read = 0;
    
    while((bytes_read=read(fd_read, &buf, BUF_SIZE))>0){
        write(fd_write, &buf, bytes_read);
    }

    return 0;
}