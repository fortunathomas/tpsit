/* Esercizio 1: Scambio dati semplice tramite Pipe (Padre e Figlio)
Scrivere un programma C in cui il processo padre crea una pipe anonima tramite
pipe(fd) e genera un processo figlio tramite fork(). Il figlio calcola la somma
di tutti i numeri pari contenuti in un array di 10 interi e invia il risultato
al padre scrivendolo nella pipe. Il padre, nel frattempo, calcola la somma dei
numeri dispari dello stesso array, legge il risultato inviato dal figlio tramite
read(), attende la terminazione del figlio con wait(NULL) e stampa a schermo le
due somme parziali e la somma totale complessiva. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    const int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
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
        int risultato = 0;
        printf("\n--------FIGLIO--------\n");
        
        for (int i = 0; i < 10; i++) {
            risultato += array[i];
            printf("\nSomma parziale n: %d. Risultato: %d", i, risultato);
        }

        write(fd[1], &risultato, sizeof(int));
        
        close(fd[1]);
        exit(0);
    }
    
    //Processo padre
    wait(NULL);
    printf("\n--------PADRE--------\n");
    
    int risultatoDispari = 0;
    for (int i = 0; i < 10; i++) {
        if (array[i] % 2 != 0) {
            risultatoDispari += array[i];
            printf("\nSomma parziale n: %d. Risultato: %d", i, risultatoDispari);
        }
    }
    
    close(fd[1]);
    printf("\n\nI risultati finali sono: ");
    int buffer;
    
    int bytesLetti = read(fd[0], &buffer, sizeof(buffer));
    
    printf("%d e %d", buffer, risultatoDispari);
    close(fd[0]);
    
    
    
    return 0;
}