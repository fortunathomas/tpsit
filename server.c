#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FIFO_PATH "/tmp/clientFIFO"
#define BUF_SIZE 256

int main(void) {
    int fd = open(FIFO_PATH, O_RDONLY); 
    if (fd == -1) {
        perror("Errore open reader");
        exit(EXIT_FAILURE);
    }
    
    
    char buffer[BUF_SIZE];
    ssize_t n = read(fd, buffer, BUF_SIZE);
    if (n < 1 && n != 0)
        perror("Errore read");
    else
        printf("[SERVER] %s", buffer);
    
    close(fd);
    
    if (unlink(FIFO_PATH) == -1)
        perror("Errore unlink");
    return 0;
}