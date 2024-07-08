#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int roll_number;
    char name[50];
    float marks;
} Student;


void addStudent(Student **students, int *numStudents);
void displayStudents(Student *students, int numStudents);
void searchStudent(Student *students, int numStudents, int rollNumber);
void modifyStudent(Student *students, int numStudents, int rollNumber);
void deleteStudent(Student **students, int *numStudents, int rollNumber);
void saveToFile(Student *students, int numStudents, const char *filename);
void loadFromFile(Student **students, int *numStudents, const char *filename);

int main() {
    Student *students = NULL;
    int numStudents = 0;
    int choice, rollNumber;
    char filename[] = "students.dat";
    do {
        printf("\nStudent Record System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Modify Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Save Records to File\n");
        printf("7. Load Records from File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&students, &numStudents);
                break;
            case 2:
                displayStudents(students, numStudents);
                break;
            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &rollNumber);
                searchStudent(students, numStudents, rollNumber);
                break;
            case 4:
                printf("Enter roll number to modify: ");
                scanf("%d", &rollNumber);
                modifyStudent(students, numStudents, rollNumber);
                break;
            case 5:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollNumber);
                deleteStudent(&students, &numStudents, rollNumber);
                break;
            case 6:
                saveToFile(students, numStudents, filename);
                break;
            case 7:
                loadFromFile(&students, &numStudents, filename);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
                break;
        }

    } while (choice != 8);


    if (students != NULL) {
        free(students);
    }

    return 0;
}

void addStudent(Student **students, int *numStudents) {
    (*numStudents)++;
    *students = (Student *)realloc(*students, (*numStudents) * sizeof(Student));

    printf("Enter Roll Number: ");
    scanf("%d", &((*students)[*numStudents - 1].roll_number));
    printf("Enter Name: ");
    scanf(" %[^\n]s", (*students)[*numStudents - 1].name);
    printf("Enter Marks: ");
    scanf("%f", &((*students)[*numStudents - 1].marks));
}

void displayStudents(Student *students, int numStudents) {
    if (numStudents == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n%-15s %-30s %-10s\n", "Roll Number", "Name", "Marks");
    for (int i = 0; i < numStudents; i++) {
        printf("%-15d %-30s %-10.2f\n", students[i].roll_number, students[i].name, students[i].marks);
    }
}

void searchStudent(Student *students, int numStudents, int rollNumber) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].roll_number == rollNumber) {
            printf("Student Found:\n");
            printf("Roll Number: %d\n", students[i].roll_number);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", rollNumber);
}

void modifyStudent(Student *students, int numStudents, int rollNumber) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].roll_number == rollNumber) {
            printf("Enter new Name: ");
            scanf(" %[^\n]s", students[i].name);
            printf("Enter new Marks: ");
            scanf("%f", &students[i].marks);
            printf("Record modified successfully.\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", rollNumber);
}

void deleteStudent(Student **students, int *numStudents, int rollNumber) {
    int found = 0;
    for (int i = 0; i < *numStudents; i++) {
        if ((*students)[i].roll_number == rollNumber) {
            found = 1;
            for (int j = i; j < (*numStudents) - 1; j++) {
                (*students)[j] = (*students)[j + 1];
            }
            (*numStudents)--;
            *students = (Student *)realloc(*students, (*numStudents) * sizeof(Student));
            printf("Student with Roll Number %d deleted successfully.\n", rollNumber);
            break;
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

void saveToFile(Student *students, int numStudents, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fwrite(&numStudents, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), numStudents, file);

    fclose(file);
    printf("Student records saved to %s successfully.\n", filename);
}

void loadFromFile(Student **students, int *numStudents, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fread(numStudents, sizeof(int), 1, file);
    *students = (Student *)realloc(*students, (*numStudents) * sizeof(Student));
    fread(*students, sizeof(Student), *numStudents, file);

    fclose(file);
    printf("Student records loaded from %s successfully.\n", filename);
}
