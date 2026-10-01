/* Esercizio 2: Gestione di N figli in parallelo
Scrivere un programma C in cui il processo padre
genera 3 processi figli simultanei. Ogni figlio deve stampare il proprio PID,
attendere 2 secondi e poi terminare. Il padre deve attendere che tutti e 3 i
figli abbiano completato l'esecuzione prima di stampare un messaggio finale e chiudersi. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main2() {
    for (int i = 0; i < 3; i++)
    {
        pid_t ritorno = fork();

        //Controllo errore nel fork()
        if (ritorno < 0) {
            perror("Errore nel fork\n");
            exit(-1);
        }

        if (!ritorno) {
            printf("Processo figlio n: %d. PID: %d\n", i +1, getpid());
            exit(0);
        }
    }

    wait(NULL);
    printf("Processo padre: 'finito'\n");

    return 0;
}
