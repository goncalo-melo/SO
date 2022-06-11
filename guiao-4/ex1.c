#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

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

    write(fd_stdout, "terminei\n", sizeof("terminei\n"));

    return 0;
}