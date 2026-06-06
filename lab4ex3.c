#include <stdio.h>

// Define a struct named 'Rectangle'
struct Rectangle {
    int length;
    int width;
};

// Function to calculate the area of a rectangle
int calculateArea(struct Rectangle *r) {
    return (r->length * r->width);
}

int main() {
    // Declare a variable of type 'Rectangle'
    struct Rectangle rect;

    // Assign values to the struct members
    rect.length = 5;
    rect.width = 3;

    // Calculate and print the area using a function
    printf("Area of the rectangle: %d\n", calculateArea(&rect));

    return 0;
}
