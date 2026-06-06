#include <stdio.h>
#include <string.h>

typedef struct {
    int empID;
    char name[25];
    float salary;
} Employee;

void addEmployee(Employee *e, int id, const char *name, float salary) {
    e->empID = id;
    strcpy(e->name, name);
    e->salary = salary;
}

void displayEmployee(Employee *e) {
    printf("Employee ID: %d\n", e->empID);
    printf("Name: %s\n", e->name);
    printf("Salary: %.2f\n", e->salary);
    printf("---------------------\n");
}

int main() {
    Employee emp[3];

    addEmployee(&emp[0], 101, "Emp 1", 50000.99);
    addEmployee(&emp[1], 102, "Emp 2", 60000.67);
    addEmployee(&emp[2], 103, "Emp 3", 55000.98);

    printf("Employee Records:\n");

    for (int i = 0; i < 3; i++) {
        displayEmployee(&emp[i]);
    }

    return 0;
}
