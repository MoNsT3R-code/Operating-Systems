#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define SHM_NAME "/ai_shared_mem"
#define SIZE 256

int main() {
    int shm_fd;
    char *shm_ptr;

    // Open shared memory
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SIZE);
    shm_ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    char input[SIZE];
    while (1) {
        printf("You: ");
        fgets(input, SIZE, stdin);
        input[strcspn(input, "\n")] = 0;

        strcpy(shm_ptr, input);

        if (strcmp(input, "X") == 0)
            break;

        while (strlen(shm_ptr) == strlen(input)) {
            usleep(100000);
        }

        printf("AI: %s\n", shm_ptr);
    }

    munmap(shm_ptr, SIZE);
    close(shm_fd);
    shm_unlink(SHM_NAME);
    return 0;
}