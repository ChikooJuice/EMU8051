#include <iostream>
#include <sys/mman.h>
#include <cstring>
#include <unistd.h>
#include "sync.cpp"
#include <stdlib.h>
#include <fcntl.h>
#include <cerrno>

#define MMAP_SIZE 1024

int main() {
    int x,y;

    char buffer[] = "a";
    const char *file_name = "/a";

    int fd = shm_open (file_name, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        printf("shm open failed \n");
        std::cout << "shm : " << strerror(errno) << std::endl;
        return 0;
    }


    ftruncate(fd, sizeof(sem));

    sem *shared_mem_pointer = (sem*)mmap(0, sizeof(sem), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    shared_mem_pointer->init();

    if (shared_mem_pointer == MAP_FAILED) {
        printf("MMAP failed \n");
        return 0;
    }
    // mmap is successful 


    strcpy(shared_mem_pointer->buffer, buffer);
    printf("1. %s \n", shared_mem_pointer->buffer);

    // creating a child process. 
    pid_t pid_child = fork();

    if (pid_child < 0 ) {
        printf("Forking failed \n");
        return 0;
    }
    if (pid_child == 0) {
        printf("exec-ed child \n");
        execlp("./reader", "./reader", NULL);
    }

    // sem_getvalue(&shared_mem_pointer->mem_read, &x);
    // sem_getvalue(&shared_mem_pointer->mem_updated, &y);
    // printf("writer loop start: mem_read : %d | mem_updated : %d \n", x, y);
    int i = 0;
    while(i < 1000) {
        
        sem_wait(&shared_mem_pointer->mem_read);
        sem_wait(&shared_mem_pointer->semaphore);        

            printf("from writer :  %s \n", shared_mem_pointer->buffer);
        i++;
        sem_post(&shared_mem_pointer->semaphore);
        sem_post(&shared_mem_pointer->mem_updated);
        
        // sem_getvalue(&shared_mem_pointer->mem_read, &x);
        // sem_getvalue(&shared_mem_pointer->mem_updated, &y);
        // printf("writer loop : mem_read : %d | mem_updated : %d \n", x, y);
    }

    return 0;

}