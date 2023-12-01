#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t semaphore;
int var;

void* producer(void* arg) {
    sem_wait(&semaphore);
    printf("In producer critical section\n");
    var = 25;
    sem_post(&semaphore);
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    sem_wait(&semaphore);
    printf("In consumer critical section\n");
    printf("Accessing var %d\n", var);
    sem_post(&semaphore);
    pthread_exit(NULL);
}

int main() {
    pthread_t p, c;
    sem_init(&semaphore, 0, 1);
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);
    sem_destroy(&semaphore);
}