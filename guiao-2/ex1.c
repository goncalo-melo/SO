#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int main(){

    printf("Pai:\n Processo pai: %d\n Processo pai do pai: %d\n", getpid(), getppid());

    return 0;
}