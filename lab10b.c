//example 1

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
 
pthread_t tid[2]; 
int enable=1;
pthread_mutex_t lock;

void* thread1(void* arg);
void* thread2(void* arg);

int main(void) {
	printf("Enter 1 to enable Mutex, 0 to disable: ");
	scanf("%d",&enable);
	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\n mutex init has failed\n");
		return 1;	}

	pthread_create(&(tid[0]),NULL,&thread1, NULL);
	pthread_create(&(tid[1]),NULL,&thread2, NULL);

	pthread_join(tid[0], NULL);  //wait for thread0 to completely execute.
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);

	return 0;
}

void* thread1(void* arg) {
	if(enable) pthread_mutex_lock(&lock);
	for (int i = 0; i < 200; i++) {
	  printf("-"); fflush(stdout);  //refresh console for printing.
  	  for(int j=0;j<0x3FFFFF;j++);  //keep the thread busy in CPU
	}
	if(enable) pthread_mutex_unlock(&lock);
}

void* thread2(void* arg) {
	if(enable) pthread_mutex_lock(&lock);
	for (int i = 0; i < 200; i++) {
	  printf("x");fflush(stdout);
    	  for(int j=0;j<0x3FFFFF;j++);
	}
	if(enable) pthread_mutex_unlock(&lock);
}


//example 2

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void* thread1(void* arg);
void* thread2(void* arg);
void* deadlock_detect(void* arg); //thread3

pthread_mutex_t lock1; //lock1 represents a resource e.g. "a file on disk"
pthread_mutex_t lock2; //lock2 represents a resource e.g. "a USB port"
int lock1th1=0, lock2th2=0;

int main(){
	pthread_t tid[3];
	pthread_mutex_init(&lock1, NULL);
	pthread_mutex_init(&lock2, NULL);
	
	pthread_create(&tid[0],NULL,&thread1,NULL);
	pthread_create(&tid[1],NULL,&thread2,NULL);
	pthread_create(&tid[2],NULL,&deadlock_detect,NULL);

	for(int i=0; i<2; i++) pthread_join(tid[i],NULL);
	pthread_mutex_destroy(&lock1);
	pthread_mutex_destroy(&lock2);
	
	return 0;
}

void* thread1(void* arg){
	while(1){
		pthread_mutex_lock(&lock1); lock1th1=1;
		for(int i=0;i<0xFFF;i++);  //Add delay between resource requests
		pthread_mutex_lock(&lock2); lock1th1=0;
			for(int i=0;i<0xFFFFFF;i++);//thread busy doing some work
			printf("1");                //prints when thread 1 is done
		pthread_mutex_unlock(&lock2);		
		pthread_mutex_unlock(&lock1);		
	}
}

void* thread2(void* arg){
	while(1){
		pthread_mutex_lock(&lock2); lock2th2=1;
		for(int i=0;i<0xFFF;i++);  //Add delay between resource requests
		pthread_mutex_lock(&lock1); lock2th2=0;

			for(int i=0;i<0xFFFFFF;i++); //thread busy doing some work
			printf("2");                 //prints when thread 2 is done
		pthread_mutex_unlock(&lock1);		
		pthread_mutex_unlock(&lock2);		
	}
}

void* deadlock_detect(void* arg){
	while(1){
		fflush(stdout);
		for(int i=0;i<0xFFF;i++); //delay between iterations
		if(lock1th1 && lock2th2) {
			pthread_mutex_destroy(&lock1);
			pthread_mutex_destroy(&lock2);
			break;
		}
	}
			printf("! Deadlock Occurred ! (Ctrl+C to terminate)\n");
}


//TASK 2


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int account_balance = 0;
pthread_mutex_t bank_lock;

void *deposit(void *arg) {
    for (int i = 0; i < ____; i++) {              // (1) number of deposits
        pthread_mutex_lock(&____);                // (2) lock before update
        account_balance += ____;                  // (3) deposit amount
        pthread_mutex_unlock(&____);              // (4) unlock after update
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <num_threads>\n", argv[0]);
        return 0;
    }

    int n = atoi(____);                        // (5) number of threads from user
    pthread_t tid[n];

    pthread_mutex_init(&____, NULL);           // (6) initialize mutex

    for (int i = 0; i < n; i++) {
        pthread_create(&tid[i], NULL, ____, NULL);       // (7) thread function
    }

    for (int i = 0; i < n; i++) {
        pthread_join(tid[i], ____);                      // (8) join threads
    }

    printf("Final account balance: %d\n", ____);         // (9) print balance

    pthread_mutex_destroy(&____);                        // (10) destroy mutex
    return 0;
}
