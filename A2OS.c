#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct {
    int *arr;
    int start;
    int end;
    long long sum;
} Data;

void* sum_part(void *arg) {
    Data *d = (Data*)arg;
    d->sum = 0;

    for(int i = d->start; i < d->end; i++) {
        d->sum += d->arr[i];
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Usage: %s <array_size> <thread_count>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int T = atoi(argv[2]);

    int *arr = malloc(N * sizeof(int));
    pthread_t threads[T];
    Data data[T];

    srand(time(NULL));

    // Measure array initialization time
    clock_t start_init = clock();

    for(int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }

    clock_t end_init = clock();
    double init_time = (double)(end_init - start_init) / CLOCKS_PER_SEC;

    // Thread work division
    int part = N / T;

    clock_t start_sum = clock();

    for(int i = 0; i < T; i++) {
        data[i].arr = arr;
        data[i].start = i * part;
        data[i].end = (i == T - 1) ? N : (i + 1) * part;

        pthread_create(&threads[i], NULL, sum_part, &data[i]);
    }

    long long total = 0;

    for(int i = 0; i < T; i++) {
        pthread_join(threads[i], NULL);
        total += data[i].sum;
    }

    clock_t end_sum = clock();
    double sum_time = (double)(end_sum - start_sum) / CLOCKS_PER_SEC;

    printf("Array initialization time: %f s\n", init_time);
    printf("Summation time with %d threads: %f s\n", T, sum_time);
    printf("Total sum of %d elements is: %lld\n", N, total);

    free(arr);

    return 0;
}