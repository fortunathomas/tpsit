#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>       /* per open() e O_WRONLY */
#include <sys/stat.h>    /* per mkfifo() */
#include <unistd.h>      /* per write() e close() */
#include <string.h>      /* per strlen() */
#include <errno.h>       /* per errno e EEXIST */
#include <signal.h>

#define FIFO_PATH "/tmp/clientFIFO"
#define BUF_SIZE 256

int main() {
    signal(SIGPIPE, SIG_IGN);
    
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        if (errno != EEXIST) {
            perror("Errore mkfifo");
            exit(EXIT_FAILURE);
        }
    }

    int fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1) {
        perror("Errore open writer");
        exit(EXIT_FAILURE);
    }
    
    while (1) {
        char buffer[BUF_SIZE] = {0};
        printf("Inserisci una stringa: ");
 
        if (fgets(buffer, BUF_SIZE, stdin) == NULL)
            break;
 
        buffer[strcspn(buffer, "\n")] = '\0';
        
        if (write(fd, buffer, BUF_SIZE) < 0)
            break;
 
        if (strcmp(buffer, "QUIT") == 0)
            break;
    }


    close(fd);
    return 0;
}