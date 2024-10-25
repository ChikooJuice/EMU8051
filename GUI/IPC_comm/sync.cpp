#ifndef SYNC_CPP
#define SYNC_CPP
#include <semaphore.h>


class sem {
    public:
    int sem_t;
    char buffer[4096];
    sem():sem_t(1) {}
};

#endif