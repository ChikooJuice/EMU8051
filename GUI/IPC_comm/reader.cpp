//program to fork another process, and interact with it. 

#include <iostream>
#include <sys/mman.h>
#include <cstring>
#include <unistd.h>
#include "sync.cpp"
#include <fcntl.h>


int main () {
    printf("--------------- IN READER PROCESS----------- \n");

    const char *file_name = "/a";

    int fd = shm_open (file_name, O_RDWR, 0666);

    sem *shared_mem_pointer = (sem*)mmap(0, sizeof(sem), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    std::string msg = "hello world ";
    std::string r_msg;
    printf("R ->here sem : %d \n", shared_mem_pointer->sem_t);
    char *buffer;
    int i = 0;
    while(true) {
        if(shared_mem_pointer->sem_t == 0) continue;

        if (shared_mem_pointer->sem_t == 1) {

            r_msg = msg + std::to_string(i);
            shared_mem_pointer->sem_t = 0;
            strcpy(shared_mem_pointer->buffer, r_msg.c_str());
            shared_mem_pointer->sem_t = 1;
            sleep(1);
            i++;
        }

    }
    return 0;

}