#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

// --- myln ---

char readln_buf[2048];

int readln_bud_end;

int readln_buf_pos;


int readc(int fd, char *c){
    //verifica se tenho mais bytes para ler
    //se tiver, retorna escreve no endereço(c) e atualiza estado global(pos atual)
    //se nao tiver, vai ler a disco, e retorna um carater atualizando o estado)

    return read(fd, c, 1);
}

ssize_t readln(int fd, char *line, size_t size){
    int i;

    for(i = 0; i < size && read(fd, &line[i], 1) > 0; i++){ 
        if(line[i] == '\n'){
            i++;
            break;
        }
    }

    return i;
}


ssize_t readln_improved(int fd, char *line, size_t size){
    int n_bytes = read(fd, line, size);
    char *backup = line;
    char *pos = strchr(line, '\n');

    if(pos){
        lseek(fd, -(line-pos+1), SEEK_CUR);
    }

    return pos-backup+1;
}

int main(int argc, char *argv[]){
    int fd_read = open(argv[1], O_RDONLY);

    if(fd_read < 0){
        perror("Open file_read\n");
        return 1;
    }

    char buf[BUF_SIZE];
    char number[10];
    int n_bytes = 0;
    int line_count = 1;

    while((n_bytes = readln(fd_read, buf, BUF_SIZE)) > 0){ // usar readln ou readln_improved
        if(n_bytes != 1024){
            sprintf(number, "%d  ", line_count);
            write(1, &number, 3);
            line_count++;
        }
        write(1, &buffer, n_bytes);
    }

    close(fd_read);

    return 1;
}