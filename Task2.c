//task2


//Process 1: Control Center:



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

    char tempC[20];

    printf("Enter temperature in Celsius: ");
    fgets(tempC, sizeof(tempC), stdin);

    int fd1 = open(PIPE1, O_WRONLY);
    write(fd1, tempC, strlen(tempC) + 1);
    close(fd1);

    char response[100];

    int fd2 = open(PIPE2, O_RDONLY);
    read(fd2, response, sizeof(response));
    close(fd2);

    printf("Received from sensor unit: %s\n", response);

    return 0;
}




