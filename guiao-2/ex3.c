#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){

    for(int i = 1; i<=10; i++){
        pid_t pid = fork();

        if(pid == 0){
            printf("Processo pai : %d\nProcesso filho : %d\n", getppid(), getpid());
        
            _exit(i);
        }
        else{
            int status;
            wait(&status);

            printf("Codigo saida : %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
/*

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define N_PROCS 10

int main(){

    pid_t n_procs[N_PROCS];

    for(int i=1; i<=N_PROCS; i++){
        pid_t pid;
        if((pid=fork())==0){
            printf("Filho: processo do pai: %d | processo do filho: %d | número de ordem: %d\n", getppid(), getpid(), i);
            _exit(i);
        }
        else{
            n_procs[i-1] = pid;
        }

    }
    
    for(int i=1; i<=N_PROCS; i++){
             
            
        int status;
        pid_t terminated_pid = waitpid(n_procs[i-1], &status, 0);

        if(WIFEXITED(status)){ 
            printf("Pai: processo do filho: %d | código: %d\n", terminated_pid, WEXITSTATUS(status));
        }
    }

    return 0;
}
*/