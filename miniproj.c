#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[100];
    float salary;
    float taxDeductions;
};

void addEmployee(struct Employee employees[], int *size) {
    printf("Enter employee ID: ");
    scanf("%d", &employees[*size].id);
    printf("Enter employee name: ");
    scanf("%s", employees[*size].name);
    printf("Enter employee salary: ");
    scanf("%f", &employees[*size].salary);
    printf("Enter tax deductions: ");
    scanf("%f", &employees[*size].taxDeductions);
    (*size)++;
}

float calculateSalary(struct Employee employee) {
    return employee.salary - employee.taxDeductions;
}
void displayEmployeeDetails(struct Employee employee) {
    printf("Employee ID: %d\n", employee.id);
    printf("Employee Name: %s\n", employee.name);
    printf("Salary: %.2f\n", employee.salary);
    printf("Tax Deductions: %.2f\n", employee.taxDeductions);
    printf("Net Salary: %.2f\n", calculateSalary(employee));
}

void updateSalary(struct Employee *employee) {
    printf("Enter new salary: ");
    scanf("%f", &employee->salary);
}

int main() {
    struct Employee employees[100];
    int size = 0;
    int choice;
    int id;

    while (1) {
        printf("Employee Payroll System\n");
        printf("1. Add new employee\n");
        printf("2. Display employee payroll details\n");
        printf("3. Update salary information\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &size);
                break;
            case 2:
                printf("Enter employee ID: ");
                scanf("%d", &id);
                for (int i = 0; i < size; i++) {
                    if (employees[i].id == id) {
                        displayEmployeeDetails(employees[i]);
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter employee ID: ");
                scanf("%d", &id);
                for (int i = 0; i < size; i++) {
                    if (employees[i].id == id) {
                        updateSalary(&employees[i]);
                        break;
                    }
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}