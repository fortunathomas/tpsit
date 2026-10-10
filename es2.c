/* Esercizio 2: Comunicazione bidirezionale tramite due Pipe
Scrivere un programma C in cui il processo padre comunica con un processo figlio
utilizzando due pipe anonime (pipe1 e pipe2). Il padre legge una stringa di testo
inserita dall'utente da tastiera e la invia al figlio tramite pipe1. Il figlio legge
la stringa da pipe1, la trasforma in lettere maiuscole, conta il numero di vocali presenti
e salva entrambi i dati in una struttura C (struct Messaggio). Il figlio invia la struttura
al padre tramite pipe2. Il padre legge la struttura da pipe2, attende la terminazione del
figlio con wait(NULL) e stampa a schermo la stringa maiuscola e il numero di vocali. */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

struct Messaggio {
    char stringa[100];
    int vocali;
};

int main() {
    int pipe1[2];
    int pipe2[2];

    //Errore nel pipe
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        fprintf(stderr, "Errore nelle pipe");
        exit(-1);
    }

    //Fork 1
    pid_t ritorno = fork();

    //Errore fork	
    if (ritorno == -1) {
        fprintf(stderr, "Errore nel fork");
        exit(-2);
    }

    //Processo padre
    if (ritorno > 0) {
        close(pipe1[0]);
        close(pipe2[1]);
        
        char stringa[100];
        printf("[PADRE 1] Inserisci una stringa: ");
        if (fgets(stringa, sizeof(stringa), stdin) != NULL) {
            stringa[strcspn(stringa, "\n")] = '\0';
        }

        write(pipe1[1], &stringa, sizeof(stringa));
        close(pipe1[1]);
        
        
        struct Messaggio msg;
        read(pipe2[0], &msg, sizeof(struct Messaggio));
        close(pipe2[0]);
        
        wait(NULL);
        
        printf("\n[PADRE 2] Stringa: %s\nNumero vocali: %d", msg.stringa, msg.vocali);
    } else { //Processo figlio
        close(pipe1[1]);
        close(pipe2[0]);
        
        char buffer[100];
        read(pipe1[0], &buffer, sizeof(buffer));
        close(pipe1[0]);
        
        struct Messaggio msg;
        strcpy(msg.stringa, buffer);
        msg.vocali = 0;
        
        for (int i = 0; msg.stringa[i] != '\0' ; i++) {
            char c = toupper(msg.stringa[i]);
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                msg.vocali++;
            }
        }
        
        write(pipe2[1], &msg, sizeof(struct Messaggio));
        close(pipe2[1]);
        
        exit(3);
    }
    
    
    return 0;
}