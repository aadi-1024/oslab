#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int common = 10;
sem_t sem;

void* Increment(void* arg) {
    sem_wait(&sem);
    common++;
    sem_post(&sem);
    printf("common variable updated to %d\n", common);
    pthread_exit(NULL);
}

void* Decrement(void* arg) {
    sem_wait(&sem);
    common--;
    sem_post(&sem);
    printf("common variable updated to %d\n", common);
    pthread_exit(NULL); 
}

int main() {
    sem_init(&sem, 0, 1);

    pthread_t t1, t2;
    int i = 5, j = 11;
    pthread_create(&t2, NULL, Decrement, &i);
    pthread_create(&t1, NULL, Increment, &j);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&sem);
    printf("%d\n", common);
}