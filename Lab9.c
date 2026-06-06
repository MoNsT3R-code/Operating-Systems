//Task 2:

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int alerts = 0;

void fire_alert(int sig) {
    alerts++;
    printf("Control Room: Fire alert #%d received!\n", alerts);
    if (alerts == 3) {
        printf("Control Room: Silencing alarm.\n");
        kill(0, SIGTERM);
    }
}

int main() {
    pid_t pid = fork();

    if (pid == 0) { // Child = Fire Sensor
        for (int i = 1; i <= 5; i++) {
            printf("Fire Sensor: Smoke detected #%d\n", i);
            kill(getppid(), SIGUSR1);
            sleep(1);
        }
        exit(0);

    } else if (pid > 0) { // Parent = Control Room
        signal(SIGUSR1, fire_alert);
        signal(SIGTERM, SIG_IGN);

        while (1) pause();
    }

    return 0;
}


