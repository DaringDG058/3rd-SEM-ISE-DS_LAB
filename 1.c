#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char usn[20];
    char dept[20];
    float marks;
};

struct Student *students = NULL;
int count = 0;

void addRecord();
void displayRecords();
void searchByUSN();

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Record Menu ---\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search by USN\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchByUSN();
                break;
            case 4:
                free(students);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addRecord() {
    students = (struct Student *)realloc(students, (count + 1) * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("\nEnter details for Student %d:\n", count + 1);
    
    printf("Enter USN: ");
    scanf("%s", students[count].usn);
    
    printf("Enter Name: ");
    scanf(" %[^\n]s", students[count].name);
    
    printf("Enter Department: ");
    scanf("%s", students[count].dept);
    
    printf("Enter Total Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("Record added successfully.\n");
}

void displayRecords() {
    if (count == 0) {
        printf("\nNo records to display.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    printf("%-15s %-20s %-10s %-10s\n", "USN", "Name", "Dept", "Marks");
    printf("----------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-15s %-20s %-10s %-10.2f\n", 
               students[i].usn, 
               students[i].name, 
               students[i].dept, 
               students[i].marks);
    }
}

void searchByUSN() {
    if (count == 0) {
        printf("\nNo records to search.\n");
        return;
    }

    char searchUSN[20];
    int found = 0;

    printf("\nEnter USN to search: ");
    scanf("%s", searchUSN);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].usn, searchUSN) == 0) {
            printf("\n--- Record Found ---\n");
            printf("Name: %s\n", students[i].name);
            printf("USN: %s\n", students[i].usn);
            printf("Department: %s\n", students[i].dept);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with USN %s not found.\n", searchUSN);
    }
}