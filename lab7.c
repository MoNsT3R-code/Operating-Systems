
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum_even = 0;
int sum_odd = 0;

void *compute_even(void *param); 
void *compute_odd(void *param); 

int main() {
    pthread_t tid1, tid2; 

    pthread_create(&tid1, NULL, compute_even, NULL);
    pthread_create(&tid2, NULL, compute_odd, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Sum of even numbers (1–100): %d\n", sum_even);
    printf("Sum of odd numbers (1–100): %d\n", sum_odd);
    printf("Total sum (1–100): %d\n", sum_even + sum_odd);
    return 0;
}
void *compute_even(void *param) {
    for (int i = 2; i <= 100; i += 2)
        sum_even += i;
    pthread_exit(0);
}
void *compute_odd(void *param) {
    for (int i = 1; i <= 100; i += 2)
        sum_odd += i;
    pthread_exit(0);
}





