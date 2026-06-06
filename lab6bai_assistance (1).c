#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define SHM_NAME "/ai_shared_mem"
#define SIZE 256

const char *get_quote(char c) {
    c = tolower(c);
    if (c >= 'a' && c <= 'e')
        return "Dream big.";
    else if (c >= 'f' && c <= 'j')
        return "Keep learning.";
    else if (c >= 'k' && c <= 'o')
        return "Stay humble.";
    else if (c >= 'p' && c <= 't')
        return "Be kind.";
    else if (c >= 'u' && c <= 'z')
        return "Never quit.";
    else
        return "I don’t understand.";
}

int main() {
    int shm_fd;
    char *shm_ptr;
    char prev_msg[SIZE] = "";

    shm_fd = shm_open(SHM_NAME, O_RDWR, 0666);
    shm_ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    printf("AI Assistant ready.\n");

    while (1) {
        if (strcmp(shm_ptr, prev_msg) != 0) {
            strcpy(prev_msg, shm_ptr);

            if (strcmp(shm_ptr, "X") == 0)
                break;

            const char *response = get_quote(shm_ptr[0]);
            strcpy(shm_ptr, response);
        }
        usleep(100000);
    }

    munmap(shm_ptr, SIZE);
    close(shm_fd);
    return 0;
}