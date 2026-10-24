#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

#define FIFO_PATH "/tmp/clientFIFO"
#define BUF_SIZE 256

int main(void) {
    char buffer[BUF_SIZE];
    int quit = 0;

    int fd = open(FIFO_PATH, O_RDONLY); 
    if (fd == -1) {
        perror("Errore open reader");
        exit(EXIT_FAILURE);
    }
    

    while (!quit && read(fd, buffer, BUF_SIZE) > 0) {
        if (strcmp(buffer, "QUIT") == 0)
            quit = 1;
        else
            printf("[SERVER] %s\n", buffer);
    }

    close(fd);
    
    printf("[SERVER] Fine ricezione\n");

    unlink(FIFO_PATH);
    return 0;
}