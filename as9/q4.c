#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NUM 5

int account = 500;
pthread_mutex_t lock;

void* Deposit(void* arg) {
    int* client_id = (int*)arg;
    int amount;
    int x;
    pthread_mutex_lock(&lock);
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);
    x = account;
    x += amount;
    sleep(3);
    account = x;
    pthread_mutex_unlock(&lock);
    printf("Deposited %d amount now %d\n", amount, account);

    pthread_exit(NULL);
}

void* Withdraw(void* arg) {
    int amount, x;
    pthread_mutex_lock(&lock);
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);
    if (amount > account) {
        printf("Limit exceeded\n");
    } else {
        x = account;
        x -= amount;
        sleep(3);
        account = x;
    }
    pthread_mutex_unlock(&lock);
    printf("Withdrawn %d now %d\n", amount, account);

    pthread_exit(NULL);
}

int main() {
    pthread_t thr[NUM];
    pthread_mutex_init(&lock, NULL);
    int ids[NUM];

    for (int i = 0; i < NUM; i++) {
        ids[i] = i;
    }
    for (int i = 0; i < NUM; i++) {
        if (i%2) {
            pthread_create(&thr[i], NULL, Withdraw, &ids[i]);
        } else {
            pthread_create(&thr[i], NULL, Deposit, &ids[i]);
        }
    }
    for (int i = 0; i < NUM; i++) {
        pthread_join(thr[i], NULL);
    }
    pthread_mutex_destroy(&lock);
    return 0;
}