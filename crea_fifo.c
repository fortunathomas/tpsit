#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FIFO_PATH "/tmp/fifo_test"

int main(void) {
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        if (errno != EEXIST) {
            perror("\nLa fifo esiste gia");
            exit(EXIT_FAILURE);
        }
    }
    
    printf("\nPercorso FIFO: %s\n", FIFO_PATH);
    sleep(100);
    
    unlink(FIFO_PATH);
    return 0;
}