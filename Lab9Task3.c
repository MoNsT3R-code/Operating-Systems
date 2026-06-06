// Task 3

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Drone B received an alert from Drone A\n");
}

int main() {
    pid_t other_pid;

    printf("Drone B PID: %d\n", getpid());
    printf("Enter Drone A PID: ");
    scanf("%d", &other_pid);

    signal(SIGUSR1, handler);

    while (1) {
        printf("Drone B sending alert...\n");
        kill(other_pid, SIGUSR1);
        sleep(1);
    }

    return 0;
}
