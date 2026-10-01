/* Esercizio 3: Catena di processi (Gerarchia lineare)
Scrivere un programma C che realizzi una catena a tre livelli di processi
(Nonno -> Padre -> Nipote). Il processo originale crea un figlio, il quale crea
a sua volta un proprio figlio. Ogni processo genitore deve attendere la terminazione del
rispettivo figlio prima di stampare il proprio messaggio di chiusura. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    pid_t pidPadre = fork();

    //Controllo errore nel fork()
    if (pidPadre < 0) {
        perror("Errore nel fork\n");
        exit(-1);
    }
    
    if (pidPadre == 0) {
        pid_t pidFiglio = fork();
    
        //Controllo errore nel fork()
        if (pidFiglio < 0) {
            perror("Errore nel fork\n");
            exit(-1);
        }
        
        if (!pidFiglio) {
            fprintf(stdout, "Ciao sono il nipote\n");
            fprintf(stdout, "Ho finito, PID: %d\n", getpid());
            exit(0);
        }
    }
    
    if (!pidPadre) {
        wait(NULL);
        fprintf(stdout, "Ciao sono il padre\n");
        fprintf(stdout, "Ho finito, PID: %d\n", getpid());
        exit(0);
    }

    wait(NULL);
    fprintf(stdout, "Ciao sono il nonno\n");
    fprintf(stdout, "Ho finito, PID: %d\n", getpid());
    exit(0);

    return 0;
}