#include <stdio.h>
#include <string.h>

struct Student {
    int rollNumber;
    char name[50];
    int age;
};

// Function prototypes
void insertStudent(struct Student students[], int *numStudents);
void updateStudent(struct Student students[], int numStudents);
void deleteStudent(struct Student students[], int *numStudents);
void showStudents(struct Student students[], int numStudents);
void searchStudent(struct Student students[], int numStudents);

int main() {
    struct Student students[100];
    int numStudents = 0;
    int choice;

    do {
        printf("\n\n<<<<<<< Student Management System >>>>>>>>\n\n");
        printf("1. Insert Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("4. Show Students\n");
        printf("5. Search Student\n");
        printf("0. Exit\n");
        printf("\nEnter your choice: \t");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent(students, &numStudents);
                break;
            case 2:
                updateStudent(students, numStudents);
                break;
            case 3:
                deleteStudent(students, &numStudents);
                break;
            case 4:
                showStudents(students, numStudents);
                break;
            case 5:
                searchStudent(students, numStudents);
                break;
            case 0:
                printf("\n\n***************************** EXIT PROGRAM *******************************\n\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void insertStudent(struct Student students[], int *numStudents) {
    if (*numStudents >= 100) {
        printf("Error: Maximum number of students reached!\n");
        return;
    }

    printf("\nEnter roll number: ");
    scanf("%d", &students[*numStudents].rollNumber);

    printf("Enter name: ");
    scanf("%s", students[*numStudents].name);

    printf("Enter age: ");
    scanf("%d", &students[*numStudents].age);

    (*numStudents)++;
    printf("\nSTUDENT INSERTED SUCCESSFULLY!..\n");
}

void updateStudent(struct Student students[], int numStudents) {
    int rollNumber, choice;

    printf("\nEnter roll number of the student to update: ");
    scanf("%d", &rollNumber);

    int i, found = 0;
    for (i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with roll number %d not found.\n", rollNumber);
        return;
    }

    printf("\nWhat you want to update... Please choice...\n");
    printf("1. Name\n");
    printf("2. Age\n");
    printf("0. Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\n\nEnter updated name: ");
            scanf("%s", students[i].name);
            printf("STUDENT UPDATED SUCCESSFULLY!..\n\n");
            break;
        case 2:
            printf("\nEnter updated age: ");
            scanf("%d", &students[i].age);
            printf("STUDENT UPDATED SUCCESSFULLY!..\n\n");
            break;
        case 0:
            printf("\nOK... GO TO MENU ....\n\n");
            break;
        default:
            printf("\n\nInvalid choice! Please try again.\n");
    }
}

void deleteStudent(struct Student students[], int *numStudents) {
    int rollNumber;

    printf("\nEnter roll number of the student to delete: ");
    scanf("%d", &rollNumber);

    int i, found = 0;
    for (i = 0; i < *numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with roll number %d not found.\n", rollNumber);
        return;
    }

    for (int j = i; j < *numStudents - 1; j++) {
        students[j] = students[j + 1];
    }

    (*numStudents)--;
    printf("\nStudent deleted successfully!\n");
}

void showStudents(struct Student students[], int numStudents) {
    printf("\n\n--- Student Records ---\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("-----------------------\n\n");
    }
}

void searchStudent(struct Student students[], int numStudents) {
    int rollNumber;

    printf("\nEnter roll number of the student to search: ");
    scanf("%d", &rollNumber);

    int i, found = 0;
    for (i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with roll number %d not found.\n", rollNumber);
        return;
    }

    printf("\nRoll Number: %d\n", students[i].rollNumber);
    printf("Name: %s\n", students[i].name);
    printf("Age: %d\n", students[i].age);
}
