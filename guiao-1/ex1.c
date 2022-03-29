#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 1024

//--- mycp ---

int main(int argc, char *argv[3]){

    int fd_read = open(argv[1], O_RDONLY);

     if(fd_read<0){
        perror("erro ao abrir o ficheiro");
        return 1;
    }

    int fd_write = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0640);

    if(fd_write<0){
        perror("erro ao abrir ficheiro1");
        return 1;
    }

    char buf[BUF_SIZE];
    int bytes_read=0;
    
    while((bytes_read=read(fd_read, &buf, BUF_SIZE))>0){
        
        write(fd_write, &buf, bytes_read);
    }

    close(fd_read);
    close(fd_write);



    return 0;   
}