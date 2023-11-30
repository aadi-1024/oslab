#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>

int main() {
    const int size = 4096;
    const char* name = "shmem";

    int shm_fd = shm_open(name, O_RDONLY, 0666);
    void* ptr = mmap(0, size, PROT_READ, MAP_SHARED, shm_fd, 0);

    printf("%s\n", (char*)ptr);
    shm_unlink(name);
}