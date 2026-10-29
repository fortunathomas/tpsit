/* Modifica l'esercizio precedente in modo che il padre non aspetti il figlio:
 lancia il comando e torna subito al prompt. Osserva come l'output dei processi
 paralleli si mescola. Poi aggiungi una chiamata a waitpid() con WNOHANG per
 raccogliere i figli terminati senza bloccarsi. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX 256

int main() {
    int fd[2];
    
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
            open(fd[1], O_RDWR);
            char *args[] = { riga, NULL };
            execvp(riga, args);
            
            printf("\nErrore nell'exec\n");
            exit(EXIT_FAILURE);
        }
        
        //PADRE
        if (pid > 0) {
            int result = waitpid(pid, &status, WNOHANG);
            
            if (result == 0) {
                printf("\n[PADRE] Il figlio non ha finito\n");
                sleep(1);
            } else if (result == pid) {
                if (WIFEXITED(status)) {
                    printf("\n[PADRE] Il figlio ha finito con codice %d\n", WEXITSTATUS(status));
                }
                break;
            } else {
                perror("Errore WaitPID");
                break;
            }
        }
    }
    
    return 0;
}