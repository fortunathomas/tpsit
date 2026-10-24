#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>       /* per open() e O_WRONLY */
#include <sys/stat.h>    /* per mkfifo() */
#include <unistd.h>      /* per write() e close() */
#include <string.h>      /* per strlen() */
#include <errno.h>       /* per errno e EEXIST */

#define FIFO_PATH "/tmp/clientFIFO"

int main() {
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
    
    printf("\n[CLIENT] Inserisci un messaggio:\n");
    
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    write(fd, buffer, strlen(buffer) + 1);

    close(fd);
    return 0;
}