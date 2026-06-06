#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define SIZE 256

int main() {
    // Create shared memory using mmap
    char *shm_ptr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE,
                         MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (shm_ptr == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) { // Parent process
        const char *message = "Data from parent";
        strcpy(shm_ptr, message);
        printf("Parent wrote: %s\n", shm_ptr);

        wait(NULL); // wait for child to finish
        // Cleanup
        munmap(shm_ptr, SIZE);
    } else { // Child process
        sleep(1); // give parent time to write
        printf("Child read: %s\n", shm_ptr);

        // Cleanup
        munmap(shm_ptr, SIZE);
        exit(0);
    }

    return 0;
}