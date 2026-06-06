#include <stdio.h> 

// Define a struct named 'Student', if a variable is declared outside any function its 
// scope is Global, meaning that it can be accessed from any function in the program
struct Student {
    int id;
    float gpa;
};

int main() {
    // Declare a variable of type 'Student'
    struct Student s;

    // Assign values to the struct members
    s.id = 101;
    s.gpa = 3.75;

    // Print the values
    printf("Student ID: %d\n", s.id);
    printf("Student GPA: %.2f\n", s.gpa);

    return 0;
}
