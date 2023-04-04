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

int main(int argc, char *argv[]) {

    int shm_fd;
    int items=15;
    
    shm_fd = shm_open("table", O_RDWR, 0666);

    struct data *memory = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    while(shm_fd < 0) {
        shm_fd = shm_open("table", O_RDWR, 0);
    }

    int i = 0;
    while(items > 0){
        sem_wait(&memory->mutex);
        printf("Consumer is consuming an item.\n");
        if(memory->table[i] > -1) {
            printf("Slot %d contains value: %d. Emptying the slot.\n", i, memory->table[i]);
            memory->table[i] = -1;
            i++;
        } else {
            printf("Slot %d holds no value.\n", i);
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