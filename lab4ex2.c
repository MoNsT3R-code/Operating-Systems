#include <stdio.h>
#include <stdlib.h>
// Define a struct named 'Point'
struct Point {
    int x;
    int y;
};

int main() {
    // Declare a pointer to a struct of type 'Point'
    struct Point *ptr;

    // Allocate memory for the struct using malloc
    ptr = (struct Point *)malloc(sizeof(struct Point));

    // Check if memory allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Assign values to the struct members using the pointer
    ptr->x = 5;
    ptr->y = 10;

    // Print the values
    printf("Coordinates: (%d, %d)\n", ptr->x, ptr->y);

    // Free the allocated memory
    free(ptr);

    return 0;
}
