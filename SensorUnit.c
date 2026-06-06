Sensor Unit

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define PIPE1 "pipe1"
#define PIPE2 "pipe2"

int main() {

    char input[100];

    int fd1 = open(PIPE1, O_RDONLY);
    read(fd1, input, sizeof(input));
    close(fd1);

    char output[300] = "";

    char *token = strtok(input, " ");

    while (token != NULL) {

        double celsius = atof(token);
        double fahrenheit = celsius * 9.0 / 5.0 + 32.0;

        char status[20];

        if (celsius < 0)
            strcpy(status, "FREEZING");
        else if (celsius <= 30)
            strcpy(status, "NORMAL");
        else
            strcpy(status, "HOT");

        char tempResult[100];

        sprintf(tempResult, "%.1f°F : %s\n",
                fahrenheit, status);

        strcat(output, tempResult);

        token = strtok(NULL, " ");
    }

    int fd2 = open(PIPE2, O_WRONLY);
    write(fd2, output, strlen(output) + 1);
    close(fd2);

    return 0;
}

