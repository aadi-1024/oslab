#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* calculate_sum(void* arr) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += ((int*)arr)[i];
    }
    printf("Sum is %d\n", sum);
    pthread_exit(NULL);
}
void* calculate_max(void* arr) {
    int* ptr = (int*)arr;
    int max = ptr[0];
    for (int i = 0; i < 10; i++) {
        max = max > ptr[i] ? max : ptr[i];
    }
    printf("Max is %d\n", max);
    pthread_exit(NULL);
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pthread_t sm, mx;
    pthread_create(&sm, NULL, calculate_sum, arr);
    pthread_create(&mx, NULL, calculate_max, arr);
    pthread_join(sm, NULL);
    pthread_join(mx, NULL);
}