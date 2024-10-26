//program to fork another process, and interact with it. 

#include <iostream>
#include <sys/mman.h>
#include <cstring>
#include <unistd.h>
#include "sync.cpp"
#include <fcntl.h>


int main () {
    int x,y;
    printf("--------------- IN READER PROCESS----------- \n");

    const char *file_name = "/a";

    int fd = shm_open (file_name, O_RDWR, 0666);

    sem *shared_mem_pointer = (sem*)mmap(0, sizeof(sem), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    std::string msg = "hello world ";
    std::string r_msg;
    char *buffer;
    int i = 0;
    
    while(i < 1000) {
        
        sem_wait(&shared_mem_pointer->mem_updated);
        sem_wait(&shared_mem_pointer->semaphore);

            r_msg = msg + std::to_string(i);
            strcpy(shared_mem_pointer->buffer, r_msg.c_str());
            
        sem_post(&shared_mem_pointer->mem_read);
    
        i++;
        sem_post(&shared_mem_pointer->semaphore);

        }

    return 0;

}