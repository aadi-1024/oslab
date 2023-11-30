#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>

int main() {
    const int size = 4096;
    const char* name = "shmem";
    const char* msg = "Hello World";

    int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, size);
    void* ptr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    sprintf(ptr, "%s", msg);
}