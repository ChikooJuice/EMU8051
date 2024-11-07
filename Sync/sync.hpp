#ifndef SYNC_H
#define SYNC_H

#include <stdio.h>
#include <semaphore.h>
#include "../Memory/Memory.h"
#include <unistd.h>

struct sem {
    sem_t semaphore;
    sem_t mem_updated;
    sem_t mem_read;
    char command[100];
    char buffer[sizeof(CPU)];
};
typedef struct sem sem;

void init_sem(sem *init_sem) {
    printf("Done 1 \n");
    if ( sem_init(&init_sem->semaphore, 1, 1)  < 0) {
        printf("couldn't init semaphore : semaphore \n");
        exit(0);
    } 
    printf("Done 2 \n");
    if ( sem_init(&init_sem->mem_updated, 1, 0) < 0) {
        printf("Couldnt init semaphore mem_updated \n");
        exit(0);
    }

    if ( sem_init(&init_sem->mem_read, 1, 1) < 0) {
        printf("Couldnt init semaphore mem_read \n");
        exit(0);
    }
}

#endif