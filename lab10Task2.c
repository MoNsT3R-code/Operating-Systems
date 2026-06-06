//TASK 2


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int account_balance = 0;
pthread_mutex_t bank_lock;

void *deposit(void *arg) {
    for (int i = 0; i < 10000; i++) {              // (1) number of deposits
        pthread_mutex_lock(&bank_lock);                // (2) lock before update
        account_balance += 1;                  // (3) deposit amount
        pthread_mutex_unlock(&bank_lock);              // (4) unlock after update
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <num_threads>\n", argv[0]);
        return 0;
    }

    int n = atoi(argv[1]);                        // (5) number of threads from user
    pthread_t tid[n];

    pthread_mutex_init(&bank_lock, NULL);           // (6) initialize mutex

    for (int i = 0; i < n; i++) {
        pthread_create(&tid[i], NULL, deposit, NULL);       // (7) thread function
    }

    for (int i = 0; i < n; i++) {
        pthread_join(tid[i], NULL);                      // (8) join threads
    }

    printf("Final account balance: %d\n", account_balance);         // (9) print balance

    pthread_mutex_destroy(&bank_lock);                        // (10) destroy mutex
    return 0;
}


