/* Esercizio 1: Sincronizzazione sequenziale (Padre e Figlio)
Scrivere un programma C in cui il processo padre crea un processo figlio tramite fork().
Il figlio deve stampare a schermo i numeri da 1 a 5, con una pausa di 1 secondo tra ciascun numero.
Il padre deve attendere che il figlio completi la propria esecuzione tramite wait(NULL) prima di
iniziare a stampare i numeri da 6 a 10. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main1() {
    pid_t ritorno = fork();

    //Controllo errore nel fork()
    if (ritorno < 0) {
        perror("\nErrore nel fork\n");
        exit(-1);
    }

    //Figlio
    if (!ritorno) {
        printf("\nFiglio: \n");
        for (int i = 1; i <= 5; i++) {
            fprintf(stdout, "Numero: %d\n", i);
            sleep(1);
        }

        exit(0);
    }

    wait(NULL);
    printf("\nPadre: \n");
    for (int i = 6; i <= 10; i++) {
        fprintf(stdout, "Numero: %d\n", i);
        sleep(1);
    }

    return 0;
}
