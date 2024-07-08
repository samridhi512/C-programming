#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures
typedef struct {
    int emp_id;
    char name[50];
    float basic_salary;
    float allowances;
    float deductions;
    float gross_salary;
    float net_salary;
} Employee;

// Function prototypes
void addEmployee(Employee **employees, int *numEmployees);
void displayEmployees(Employee *employees, int numEmployees);
void searchEmployee(Employee *employees, int numEmployees, int empId);
void calculateSalary(Employee *employee);
void generateSalarySlip(Employee employee);
void saveToFile(Employee *employees, int numEmployees, const char *filename);
void loadFromFile(Employee **employees, int *numEmployees, const char *filename);

int main() {
    Employee *employees = NULL;
    int numEmployees = 0;
    int choice, empId;
    char filename[] = "employees.dat"; // Change the filename as per your preference

    do {
        printf("\nEmployee Salary Slip Generation System\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Generate Salary Slip\n");
        printf("5. Save Records to File\n");
        printf("6. Load Records from File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(&employees, &numEmployees);
                break;
            case 2:
                displayEmployees(employees, numEmployees);
                break;
            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &empId);
                searchEmployee(employees, numEmployees, empId);
                break;
            case 4:
                printf("Enter Employee ID to generate salary slip: ");
                scanf("%d", &empId);
                int i;
                for (i = 0; i < numEmployees; i++) {
                    if (employees[i].emp_id == empId) {
                        calculateSalary(&employees[i]);
                        generateSalarySlip(employees[i]);
                        break;
                    }
                }
                if (i == numEmployees) {
                    printf("Employee with ID %d not found.\n", empId);
                }
                break;
            case 5:
                saveToFile(employees, numEmployees, filename);
                break;
            case 6:
                loadFromFile(&employees, &numEmployees, filename);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
                break;
        }

    } while (choice != 7);

    // Free allocated memory before exiting
    if (employees != NULL) {
        free(employees);
    }

    return 0;
}

void addEmployee(Employee **employees, int *numEmployees) {
    (*numEmployees)++;
    *employees = (Employee *)realloc(*employees, (*numEmployees) * sizeof(Employee));

    printf("Enter Employee ID: ");
    scanf("%d", &((*employees)[*numEmployees - 1].emp_id));
    printf("Enter Name: ");
    scanf(" %[^\n]s", (*employees)[*numEmployees - 1].name);
    printf("Enter Basic Salary: ");
    scanf("%f", &((*employees)[*numEmployees - 1].basic_salary));
    printf("Enter Allowances: ");
    scanf("%f", &((*employees)[*numEmployees - 1].allowances));
    printf("Enter Deductions: ");
    scanf("%f", &((*employees)[*numEmployees - 1].deductions));
}

void displayEmployees(Employee *employees, int numEmployees) {
    if (numEmployees == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\n%-10s %-30s %-15s %-15s %-15s\n", "Emp ID", "Name", "Basic Salary", "Allowances", "Deductions");
    for (int i = 0; i < numEmployees; i++) {
        printf("%-10d %-30s %-15.2f %-15.2f %-15.2f\n", employees[i].emp_id, employees[i].name, employees[i].basic_salary,
               employees[i].allowances, employees[i].deductions);
    }
}

void searchEmployee(Employee *employees, int numEmployees, int empId) {
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].emp_id == empId) {
            printf("Employee Found:\n");
            printf("Emp ID: %d\n", employees[i].emp_id);
            printf("Name: %s\n", employees[i].name);
            printf("Basic Salary: %.2f\n", employees[i].basic_salary);
            printf("Allowances: %.2f\n", employees[i].allowances);
            printf("Deductions: %.2f\n", employees[i].deductions);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", empId);
}

void calculateSalary(Employee *employee) {
    employee->gross_salary = employee->basic_salary + employee->allowances;
    employee->net_salary = employee->gross_salary - employee->deductions;
}

void generateSalarySlip(Employee employee) {
    printf("\nSalary Slip\n");
    printf("Employee ID: %d\n", employee.emp_id);
    printf("Name: %s\n", employee.name);
    printf("Basic Salary: %.2f\n", employee.basic_salary);
    printf("Allowances: %.2f\n", employee.allowances);
    printf("Deductions: %.2f\n", employee.deductions);
    printf("Gross Salary: %.2f\n", employee.gross_salary);
    printf("Net Salary: %.2f\n", employee.net_salary);
}

void saveToFile(Employee *employees, int numEmployees, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fwrite(&numEmployees, sizeof(int), 1, file);
    fwrite(employees, sizeof(Employee), numEmployees, file);

    fclose(file);
    printf("Employee records saved to %s successfully.\n", filename);
}

void loadFromFile(Employee **employees, int *numEmployees, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fread(numEmployees, sizeof(int), 1, file);
    *employees = (Employee *)realloc(*employees, (*numEmployees) * sizeof(Employee));
    fread(*employees, sizeof(Employee), *numEmployees, file);

    fclose(file);
    printf("Employee records loaded from %s successfully.\n", filename);
}

