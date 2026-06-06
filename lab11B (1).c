//Ex1

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer
    int *ptr = (int *)malloc(sizeof(int));

    // Use the allocated memory
    *ptr = 42;
    printf("Value at allocated memory: %d\n", *ptr);

    // Free the allocated memory
    free(ptr);

    return 0;

//Ex2

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an array of integers
    int *arr = (int *)malloc(5 * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Use the allocated memory
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }

    // Print the array elements
    for (int i = 0; i < 5; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}


//Ex3

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer
    int *ptr = (int *)malloc(sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Memory leak: forgetting to free the allocated memory
    // Comment out the following line to avoid the memory leak
    // free(ptr);

    return 0;
}


//Ex4


#include <stdio.h>

int main() {
    // Accessing memory beyond the allocated space
    int *arr = (int *)malloc(3 * sizeof(int));

    // Uncomment the following line to cause a segmentation fault
    // arr[3] = 42;

    // Free the allocated memory
    free(arr);

    return 0;
}



//Ex5

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a student
struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    int num_students;

    // Prompt the user for the number of students
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Dynamically allocate memory for an array of structures
    struct Student *student_array = (struct Student *)malloc(num_students * sizeof(struct Student));

    if (student_array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input student data
    for (int i = 0; i < num_students; ++i) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", student_array[i].name);
        printf("Age: ");
        scanf("%d", &student_array[i].age);
        printf("GPA: ");
        scanf("%f", &student_array[i].gpa);
    }

    // Display student data
    printf("\nStudent details:\n");
    for (int i = 0; i < num_students; ++i) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", student_array[i].name);
        printf("Age: %d\n", student_array[i].age);
        printf("GPA: %.2f\n", student_array[i].gpa);
        printf("\n");
    }

    // Free the allocated memory
    free(student_array);

    return 0;
}


//Task2

#include <stdio.h>
#include <stdlib.h>

struct Product {
    char name[40];
    float price;
    int quantity;
};

int main() {
    int count;

    printf("Enter number of products: ");
    scanf("%d", &count);

    struct Product *items = (struct Product *) ________ (count * sizeof(struct Product));

    if (items == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("\nProduct %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", items[i]. ________ );
        printf("Price: ");
        scanf("%f", &items[i]. ________ );
        printf("Quantity: ");
        scanf("%d", &items[i]. ________ );
    }

    printf("\nProduct List:\n");
    for (int i = 0; i < count; i++) {
        printf("\nProduct %d\n", i + 1);
        printf("Name: %s\n", items[i]. ________ );
        printf("Price: %.2f\n", items[i]. ________ );
        printf("Quantity: %d\n", items[i]. ________ );
    }

    FILE *fp = fopen("products.txt", "w");
    if (fp == NULL) {
        printf("Could not open file.\n");
        ________ (items);
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "Product %d\n", i + 1);
        fprintf(fp, "Name: %s\n", items[i]. ________ );
        fprintf(fp, "Price: %.2f\n", items[i]. ________ );
        fprintf(fp, "Quantity: %d\n\n", items[i]. ________ );
    }

    fclose(fp);

    ________ (items);

    return 0;
}
