#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int empID;
    char name[50];
    float basicSalary;
    float allowances;
    float grossSalary; 
};

// Function prototypes
void inputEmployees(struct Employee employees[], int count);
void computeGrossSalary(struct Employee employees[], int count);
void savePayrollToFile(const struct Employee employees[], int count);
void retrieveEmployeeSalary(const struct Employee employees[], int count);

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int count;

    // Input number of employees
    printf("Enter number of employees: ");
    scanf("%d", &count);
    getchar(); 

    // Input employee details
    inputEmployees(employees, count);

    // Compute gross salary for each employee
    computeGrossSalary(employees, count);

    // Save payroll data to file
    savePayrollToFile(employees, count);

    // Retrieve employee salary
    retrieveEmployeeSalary(employees, count);

    return 0;
}

// Function to input employee details
void inputEmployees(struct Employee employees[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Employee %d: ", i + 1);
        scanf("%d, %49[^,], ₹%f, ₹%f", &employees[i].empID, employees[i].name, &employees[i].basicSalary, &employees[i].allowances);
        getchar(); 
    }
}

// Function to compute gross salary
void computeGrossSalary(struct Employee employees[], int count) {
    for (int i = 0; i < count; i++) {
        employees[i].grossSalary = employees[i].basicSalary + employees[i].allowances;
    }
}

// Function to save payroll data to a file
void savePayrollToFile(const struct Employee employees[], int count) {
    FILE *file = fopen("payroll.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d, %s, ₹%.2f, ₹%.2f, ₹%.2f\n", employees[i].empID, employees[i].name, employees[i].basicSalary, employees[i].allowances, employees[i].grossSalary);
    }

    fclose(file);
    printf("Record saved in \"payroll.txt\"\n");
}

// Function to retrieve employee salary
void retrieveEmployeeSalary(const struct Employee employees[], int count) {
    int empID;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &empID);

    for (int i = 0; i < count; i++) {
        if (employees[i].empID == empID) {
            printf("Employee: %s\n", employees[i].name);
            printf("Gross Salary: ₹%.2f\n", employees[i].grossSalary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", empID);
}

3rd que
