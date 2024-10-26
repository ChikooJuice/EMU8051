#ifndef SYNC_CPP
#define SYNC_CPP
#include <semaphore.h>
#include <iostream>


class sem {
    public:
        sem_t semaphore;
        sem_t mem_updated;
        sem_t mem_read;
        char buffer[4096];

        void init() {
            if ( sem_init(&semaphore, 1, 1)  < 0) {
                printf("couldn't init semaphore : semaphore \n");
                exit(0);
            } 
            if ( sem_init(&mem_updated, 1, 0) < 0) {
                printf("Couldnt init semaphore mem_updated \n");
                exit(0);
            }

            if ( sem_init(&mem_read, 1, 1) < 0) {
                printf("Couldnt init semaphore mem_read \n");
                exit(0);
            }  
        }
};

#endif