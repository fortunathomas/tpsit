/* Scrivi un programma che legge comandi da tastiera in un ciclo
 (un comando per riga, senza argomenti), e per ognuno esegue il
 pattern fork + execvp. Il programma termina quando l'utente inserisce exit.
 Il padre aspetta sempre che il figlio finisca prima di chiedere il prossimo comando.
 Se il comando non esiste, stampa un messaggio di errore e continua. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX 256

int main() {
    printf("\n---------------La mia shell---------------\n");
    
    while (1) {
        char riga[MAX];
        
        do {
            printf("Inserisci un comando: \n");
            
            fgets(riga, MAX, stdin);
            riga[strcspn(riga, "\n")] = '\0';
        } while(strcmp(riga, "") == 0);
        
        if (strcmp(riga, "exit") == 0) {
            printf("\nFine del programma\n");
            break;
        }
        
        pid_t pid = fork();
        
        //FIGLIO
        if (pid == 0) {
            char *args[] = { riga, NULL };
            execvp(riga, args);
            
            printf("\nErrore nell'exec\n");
            exit(EXIT_FAILURE);
        }
        
        //PADRE
        if (pid > 0) {
            wait(NULL);
        }
    }
    
    
    return 0;
}