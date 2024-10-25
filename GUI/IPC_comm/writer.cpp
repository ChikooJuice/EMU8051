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

    if (shared_mem_pointer == MAP_FAILED) {
        printf("MMAP failed \n");
        return 0;
    }
    // mmap is successful 
    shared_mem_pointer->sem_t = 1;
    printf("sem : %d---\n", shared_mem_pointer->sem_t);



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

    while(true) {

        if(shared_mem_pointer->sem_t == 0) continue;

        if (shared_mem_pointer->sem_t == 1) {
            shared_mem_pointer->sem_t = 0;
            printf("from writer :  %s \n", shared_mem_pointer->buffer);
            shared_mem_pointer->sem_t = 1;
            sleep(1);
        }

    }



    
    return 0;


}