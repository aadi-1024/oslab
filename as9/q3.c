#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#define MSGSIZE 16

int var = 10;
sem_t sm;

int main() {
    char inbuf[MSGSIZE];
    int fd[2];
    sem_init(&sm, 0, 0);
    pipe(fd);
    pid_t p = fork();
    if (p == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (p == 0) {
        sleep(2);
        var -= 2;
        printf("child var: %d\n", var);
        sem_post(&sm);
        write(fd[1], "1", 2);
    } else {
        read(fd[0], inbuf, MSGSIZE);
        sem_init(&sm, 0, atoi(inbuf));
        sem_wait(&sm);
        var += 2;
        printf("parent var: %d\n", var);
    }
    sem_destroy(&sm);
    return 0;
}