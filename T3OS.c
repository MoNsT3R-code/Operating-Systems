#include <stdio.h>
#include <stdlib.h>

// Define the Employee structure blueprint
struct Employee {
    char name[50];
    float monthly_salary;
    int years_employed;
};

int main() {
    int num_employees;

    // 1. Prompt user for number of records
    printf("Enter the number of employees they want to enter: ");
    if (scanf("%d", &num_employees) != 1 || num_employees <= 0) {
        printf("Invalid input amount. Program terminating.\n");
        return 1;
    }

    // 2. Dynamically allocate memory for all employee records on the heap
    struct Employee *emp_array = (struct Employee *)malloc(num_employees * sizeof(struct Employee));

    // Error handling check to ensure allocation did not fail
    if (emp_array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 3. Input the details for every employee
    for (int i = 0; i < num_employees; ++i) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", emp_array[i].name);
        printf("Monthly Salary: ");
        scanf("%f", &emp_array[i].monthly_salary);
        printf("Years Employed: ");
        scanf("%d", &emp_array[i].years_employed);
    }

    // 4. Display all employee information on the screen with calculated annual salary
    printf("\n=================================");
    printf("\n        EMPLOYEE REPORT          ");
    printf("\n=================================\n");

    for (int i = 0; i < num_employees; ++i) {
        // Calculate each employee's annual salary
        float annual_salary = emp_array[i].monthly_salary * 12.0f;
        
        printf("Employee %d:\n", i + 1);
        printf("Name: %s\n", emp_array[i].name);
        printf("Monthly Salary: %.2f\n", emp_array[i].monthly_salary);
        printf("Years Employed: %d\n", emp_array[i].years_employed);
        printf("Annual Salary: %.2f\n", annual_salary);
        printf("---------------------------------\n");
    }

    // 5. Save all displayed information into a file named employees_report.txt
    FILE *fp = fopen("employees_report.txt", "w");
    if (fp == NULL) {
        printf("Could not open file for writing! Cleaning up heap memory...\n");
        free(emp_array);
        return 1;
    }

    fprintf(fp, "=================================\n");
    fprintf(fp, "        EMPLOYEE REPORT          \n");
    fprintf(fp, "=================================\n");

    for (int i = 0; i < num_employees; ++i) {
        float annual_salary = emp_array[i].monthly_salary * 12.0f;
        
        fprintf(fp, "Employee %d:\n", i + 1);
        fprintf(fp, "Name: %s\n", emp_array[i].name);
        fprintf(fp, "Monthly Salary: %.2f\n", emp_array[i].monthly_salary);
        fprintf(fp, "Years Employed: %d\n", emp_array[i].years_employed);
        fprintf(fp, "Annual Salary: %.2f\n", annual_salary);
        fprintf(fp, "---------------------------------\n");
    }

    fclose(fp);
    printf("\nReport successfully saved to 'employees_report.txt'.\n");

    // 6. Free all allocated memory before the program terminates
    free(emp_array);

    return 0;
}