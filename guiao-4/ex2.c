#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]){

    int fd_passwd = open("/etc/passwd", O_RDONLY);
    int fd_saida = open("./saida.txt", O_RDWR | O_CREAT | O_TRUNC, 0640);
    int fd_erros = open("./erros.txt", O_RDWR | O_CREAT | O_TRUNC, 0640);

    int fd_stdout = dup(1);

    dup2(fd_passwd, 0);
    close(fd_passwd);

    dup2(fd_saida, 1);
    close(fd_saida);

    dup2(fd_erros, 2);
    close(fd_erros);

    pid_t pid = fork();
    
    if(pid == 0) {
        char buffer[BUF_SIZE] = { 0 };
        ssize_t r_bytes = read(0, buffer, BUF_SIZE);
        if(r_bytes < 0) {
            perror("This didn't go well");
            _exit(1);
        }
            
        write(1, buffer, r_bytes);
        _exit(0);
    }
    else if(pid < 0){
        perror("You're forked");
        return 1;
    }
    else{
        int status;
        pid = wait(&status);
        if(WIFEXITED(status) && WEXITSTATUS(status) != 1) {
            puts("Impressos os descriptors do processo filho");
        }
        else{
            fputs("Fodeu geral\n", stderr);
        }
    }

    write(fd_stdout, "terminei\n", sizeof("terminei\n"));

    return 0;
}
