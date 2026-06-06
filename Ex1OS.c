#include <stdio.h>
#include <stdlib.h> // Essential header for malloc() and free()

struct Product {
    char name[40];
    float price;
    int quantity;
};

int main() {
    int count;

    printf("Enter number of products: ");
    scanf("%d", &count);

    // 1. Allocate memory dynamically on the heap for the structures
    struct Product *items = (struct Product *) malloc(count * sizeof(struct Product));

    if (items == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // 2. Input student data into structure members
    for (int i = 0; i < count; i++) {
        printf("\nProduct %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", items[i].name); // Strings don't need '&' here
        printf("Price: ");
        scanf("%f", &items[i].price);
        printf("Quantity: ");
        scanf("%d", &items[i].quantity);
    }

    // 3. Print the data back to the terminal screen
    printf("\nProduct List:\n");
    for (int i = 0; i < count; i++) {
        printf("\nProduct %d\n", i + 1);
        printf("Name: %s\n", items[i].name);
        printf("Price: %.2f\n", items[i].price);
        printf("Quantity: %d\n", items[i].quantity);
    }

    // 4. Set up file stream operations
    FILE *fp = fopen("products.txt", "w");
    if (fp == NULL) {
        printf("Could not open file.\n");
        free(items); // Free memory here before an early failure exit!
        return 1;
    }

    // 5. Write the stored records straight to the text file
    for (int i = 0; i < count; i++) {
        fprintf(fp, "Product %d\n", i + 1);
        fprintf(fp, "Name: %s\n", items[i].name);
        fprintf(fp, "Price: %.2f\n", items[i].price);
        fprintf(fp, "Quantity: %d\n\n", items[i].quantity);
    }

    fclose(fp);

    // 6. Final memory cleanup to avoid a memory leak
    free(items);

    return 0;
}