// TASK 3

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 100
#define MSG_SIZE 50

char log_buffer[MAX_LOGS][MSG_SIZE];   
int log_index = 0;                     
pthread_mutex_t log_lock;              

int num_threads;                       

void *logger(void *arg) {
    int thread_id = *(int *)arg;

    for (int i = 1; i <= 5; i++) {    

        pthread_mutex_lock(&log_lock);   

        if (log_index < MAX_LOGS) {     
            snprintf(log_buffer[log_index], MSG_SIZE,
                     "Thread %d: message %d", thread_id, i);

            log_index++;                
        }

        pthread_mutex_unlock(&log_lock); 
    }

    return NULL;
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <num_threads>\n", argv[0]);
        return 0;
    }

    num_threads = atoi(argv[1]);         

    pthread_t tid[num_threads];
    int thread_ids[num_threads];

    pthread_mutex_init(&log_lock, NULL);   

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i + 1;          
        pthread_create(&tid[i], NULL, logger, &thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(tid[i], NULL);
    }
    
    printf("\n--- Final Log Buffer ---\n");
    for (int i = 0; i < log_index; i++) {
        printf("%s\n", log_buffer[i]);
    }

    pthread_mutex_destroy(&log_lock);    

    return 0;
}
