/* Esercizio 4: Decisione del Padre in Base al Valore di Ritorno
Scrivere un programma C in cui il processo figlio chiede all'utente di inserire un numero intero da tastiera. Il figlio analizza il numero ed esce restituendo un codice specifico:
Codice 1: Se il numero è primo.
Codice 2: Se il numero è pari (e non primo).
Codice 3: Se il numero è dispari (e non primo). */

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int check(int n) {
    if (n <= 1) return 0;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

void stampa(int n) {
    switch (n) {
        case 1:
            printf("Il numero e primo\n");
            break;
        case 2:
            printf("Il numero e pari\n");
            break;
        case 3:
            printf("Il numero e dispari\n");
            break;
    }
}

int main() {
    pid_t ritorno = fork();

    //Controllo errore nel fork()
    if (ritorno < 0) {
        perror("Errore nel fork\n");
        exit(-1);
    }
    
    if (ritorno == 0) {
        int n;
        printf("\nInserisci un numero");
        scanf("%d", &n);
        
        if (check(n) == 1)
            exit(1);
        if (n % 2 == 0) {
            exit(2);
        }
        exit(3);
    }

    int status;
    pid_t ritornoP = wait(&status);
    
    if (WIFEXITED(status)) {
        int exit_code = WEXITSTATUS(status);
        printf("Codice: %d\n", exit_code);
        stampa(exit_code);
    } else {
        printf("[Padre] Il figlio è terminato in modo anomalo.\n");
    }
    
    return 0;
}