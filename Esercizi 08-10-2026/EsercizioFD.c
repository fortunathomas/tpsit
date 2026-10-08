#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2];

    //Errore nel pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Errore pipe");
        exit(-1);
    }

    //Fork
    pid_t ritorno= fork();

    //Errore fork	
    if (ritorno == -1) {
        fprintf(stderr, "Errore fork");
        exit(-2);
    }

    //Processo figlio
    if (!ritorno) {
        char msg[] = "Ciao Boateng";

        write(fd[1], msg, sizeof(msg));
        
        close(fd[1]);
        exit(0);
    }
    
    //Processo padre
    close(fd[1]);
    printf("Sono pronto a ricevere un Boateng...\n");
    char buffer[100];
    
    int bytesLetti = read(fd[0], buffer, sizeof(buffer));
    
    printf("%s", buffer);
    close(fd[0]);
    
    
    
    return 0;
}