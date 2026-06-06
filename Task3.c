// Task 3

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define PIPE1 "pipe1"
#define PIPE2 "pipe2"

int main() {

    mkfifo(PIPE1, 0666);
    mkfifo(PIPE2, 0666);

    char temps[100];

    printf("Enter 3 temperatures separated by spaces: ");
    fgets(temps, sizeof(temps), stdin);

    int fd1 = open(PIPE1, O_WRONLY);
    write(fd1, temps, strlen(temps) + 1);
    close(fd1);

    char response[300];

    int fd2 = open(PIPE2, O_RDONLY);
    read(fd2, response, sizeof(response));
    close(fd2);

    printf("\nResults from Sensor Unit:\n%s\n", response);

    return 0;
}

