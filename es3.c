/* Esercizio 3: Pipeline a tre processi e due Pipe
Scrivere un programma C in cui il processo padre (A)
genera due processi figli (B e C) e due pipe anonime (pipe1 e pipe2)
per collegare i tre processi in cascata. Il processo A genera 20 numeri interi
casuali tra 1 e 100 e li invia uno alla volta al processo B tramite pipe1.
Il processo B legge i numeri da pipe1, scarta quelli minori di 50, calcola
il quadrato dei rimanenti e li invia al processo C tramite pipe2. Il processo
C legge i numeri da pipe2, li stampa a schermo a mano a mano che arrivano e, al
termine della ricezione dei dati, calcola e stampa la loro media aritmetica. Il
processo A attende il completamento di B e C tramite wait(). Ciascun processo deve 
chiudere i descrittori di pipe non usati per prevenire blocchi indefiniti in lettura. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    srand(time(NULL));
    
    int pipe1[2];
    int pipe2[2];

    //Errore nel pipe
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        fprintf(stderr, "\nErrore nelle pipe");
        exit(-1);
    }
    
    
    pid_t ritornoB = fork();
    
    //Errore fork	
    if (ritornoB == -1) {
        fprintf(stderr, "\nErrore nel fork");
        exit(-2);
    }
    
    //Processo B
    if (ritornoB == 0) {
        close(pipe1[1]);
        close(pipe2[0]);
        int x;
        
        while (read(pipe1[0], &x, sizeof(int)) > 0) {
            if (x >= 50) {
                int quadrato = x * x;
                write(pipe2[1], &quadrato, sizeof(int));
            }
        }
        
        
        close(pipe1[0]);
        close(pipe2[1]);
        exit(0);
    }
    
    pid_t ritornoC = fork();
    
    //Errore fork
    if (ritornoC == -1) {
        fprintf(stderr, "\nErrore nel fork");
        exit(-2);
    }
    
    //Processo C
    if (ritornoC == 0) {
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[1]);

        int tot = 0;
        int n = 0;
        double media = 0.0;
        
        int quadrato;
        while (read(pipe2[0], &quadrato, sizeof(int)) > 0) {
            tot += quadrato;
            n++;
                
            printf("\n[FIGLIO C] Numero %d, %d", n, quadrato);
        }
            
        if (n == 0) {
            media = 0;
        } else {
            media = (double) tot / n;
        }
            
        printf("\n[PROCESSO C] Media: %f", media);
            
        close(pipe2[0]);
        exit(0);
    }
    
    //Processo A
    int array[20];
    close(pipe1[0]);
    close(pipe2[0]);
    close(pipe2[1]);
    
    for (int i = 0; i < 20; i++) {
        array[i] = rand() % 100 +1;
        write(pipe1[1], &array[i], sizeof(int));
    }
    
    close(pipe1[1]);
    wait(NULL);
    wait(NULL);
    printf("\n[PROCESSO A] Finito");
    return 0;
}