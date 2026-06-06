//Example 1:

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void sig_handler1(int num);
 
int main()
{
	/* Install a signal handler. */
	signal(SIGINT, sig_handler1);
	while(1)
	{
		printf("Hello\n");
		sleep(2);
	}
}

void sig_handler1(int num)   //customize behavior of Ctrl+C
{
	printf("You are here because of a signal: %d\n", num);
	printf("Enter Ctrl+C to exit!\n");
	signal(SIGINT, SIG_DFL);  //Re-install the default signal handler.
}

//Example 2:

#include<stdio.h>
#include <unistd.h>
#include<signal.h>

void sig_handler(int signum);

int main(){
    pid_t pid;
    signal(SIGUSR1, sig_handler); // Register the signal handler
    printf("Inside main function\n");
    pid=getpid();			//Get Process ID of this program
    kill(pid, SIGUSR1);		// Raise/send SIGUSR1
    printf("Back to main function\n");
    return 0;
}
void sig_handler(int signum){
    printf("Inside handler function\n");
}

//Example 3:

#include<stdio.h>
#include <unistd.h>
#include<signal.h>

void sig_handler1(int signum);
void sig_handler2(int signum);

int main(){
    pid_t pid;
    signal(SIGUSR1,sig_handler1); // Register the 1st signal handler
    signal(SIGUSR2,sig_handler2); // Register the 2nd signal handler
    printf("Inside main function\n");
    pid=getpid();		//Get Process ID of itself
    kill(pid,SIGUSR1);	// Send SIGUSR1 to itself
    kill(pid,SIGUSR2);	// Send SIGUSR1 to itself
    printf("Inside main function\n");
    return 0;
}
void sig_handler1(int signum){
    printf("Inside First handler function\n");
}
void sig_handler2(int signum){
    printf("Inside Second handler function\n");
}


//Example 4:

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int count = 0;

void alert_handler(int sig) {
  count++;
  printf("Parent: Received temperature alert #%d from child (SIGUSR1)\n", count);
  if (count == 3) {
        printf("Parent: 3 alerts received, sending stop signal to child.\n");
        kill(0, SIGTERM);   // stop child
  }
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {  // Child process
        for (int i = 1; i <= 5; i++) {
            printf("Child: Temperature rising... sending alert %d\n", i);
            kill(getppid(), SIGUSR1);
            sleep(2);  // delay between alerts
        }
        exit(0);
    } 
    else if (pid > 0) {  // Parent process
        signal(SIGUSR1, alert_handler);
        signal(SIGTERM, SIG_IGN);  // ignore child’s termination
        while (1) pause();  // wait for signals
    }

    return 0;
}


