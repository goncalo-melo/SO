#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


#define BUF_SIZE 1024

int main(){

    pid_t pid;
    int status;

    if((pid = fork())==0){
        printf("filho:\n processo paio: %d\n processo filho: %d\n", getppid(), getpid());
        _exit(0);

    }
    else{
        pid_t terminated_pid = wait(&status);
        if(WIFEXITED(status)){
            printf("pai:\n processo pai: %d\n processo filho: %d\n", getpid(), terminated_pid);
        }
        else{
            printf("erro");
        }
    }
    return 0;

}