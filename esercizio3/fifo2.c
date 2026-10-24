#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>       /* per open() */
#include <sys/stat.h>    /* per mkfifo() */
#include <unistd.h>      /* per read(), write(), close(), unlink() */
#include <string.h>      /* per strcmp(), strcspn() */
#include <errno.h>       /* per errno e EEXIST */

#define FIFO_PATH1 "/tmp/FIFO1"   /* programma1 -> programma2 */
#define FIFO_PATH2 "/tmp/FIFO2"   /* programma2 -> programma1 */
#define BUF_SIZE 256

int main() {
    mkfifo(FIFO_PATH1, 0666);
    mkfifo(FIFO_PATH2, 0666);

    int fd_in  = open(FIFO_PATH1, O_RDONLY);
    int fd_out = open(FIFO_PATH2, O_WRONLY);
    if (fd_in == -1 || fd_out == -1) {
        perror("Errore open");
        exit(EXIT_FAILURE);
    }

    while (1) {
        char ricevuto[BUF_SIZE] = {0};
        char msg[BUF_SIZE] = {0};

        /* 1: ASPETTA IL MESSAGGIO */
        if (read(fd_in, ricevuto, BUF_SIZE) <= 0)
            break;
        if (strcmp(ricevuto, "EXIT") == 0) {
            printf("[1] ha terminato la chat\n");
            break;
        }
        printf("[1] %s\n", ricevuto);

        /* 2: SCRIVE */
        printf("Inserisci una stringa: ");

        if (fgets(msg, BUF_SIZE, stdin) == NULL)
            break;

        msg[strcspn(msg, "\n")] = '\0';

        if (write(fd_out, msg, BUF_SIZE) < 0)
            break;
        if (strcmp(msg, "EXIT") == 0)
            break;
    }

    close(fd_in);
    close(fd_out);
    unlink(FIFO_PATH1);
    unlink(FIFO_PATH2);
    return 0;
}