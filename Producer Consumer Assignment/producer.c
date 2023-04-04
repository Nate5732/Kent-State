// Nathon Iadimarco
// Operating Systems
// 4/3/2023
// producer.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <unistd.h>

struct data {
    sem_t mutex;
    int table[2];
};

int main() {
    int shm_fd;
    int items=15;  

    shm_fd = shm_open("table", O_CREAT | O_RDWR, 0666);

    ftruncate(shm_fd, 1024);

    struct data *memory = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    
    for(int i = 0; i < 2; ++i) {
        memory->table[i] = -1;
    }

    sem_init(&memory->mutex, 1, 1);

    printf("\nProducer is ready to produce items.\n");

    int i = 0;
    while(items > 0){
        sem_wait(&memory->mutex);
        printf("Producer is producing an item.\n");

        if(memory->table[i] == -1) {
            int t = rand()%100+1;
            memory->table[i] = t;
            printf("Slot %d now contains value %d.\n", i, t);
            i++;
        } else {
            printf("Current slot is filled.\n");
        }

        if(i > 1) { i = 0; };

        items--;
        sem_post(&memory->mutex);
        sleep(rand()%2+1);
    }

    munmap(memory, sizeof(int));
    close(shm_fd);
    shm_unlink("table");

    return 0;
}