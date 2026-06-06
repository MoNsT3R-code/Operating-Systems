//Process 2: Sensor Unit:



#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define PIPE1 "pipe1"
#define PIPE2 "pipe2"

int main() {

    char input[20];

    int fd1 = open(PIPE1, O_RDONLY);
    read(fd1, input, sizeof(input));
    close(fd1);

    double celsius = atof(input);

    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    char status[20];

    if (celsius < 0)
        strcpy(status, "FREEZING");
    else if (celsius <= 30)
        strcpy(status, "NORMAL");
    else
        strcpy(status, "HOT");

    char output[100];

    sprintf(output, "%.1f°F : %s", fahrenheit, status);

    int fd2 = open(PIPE2, O_WRONLY);
    write(fd2, output, strlen(output) + 1);
    close(fd2);

    return 0;
}
