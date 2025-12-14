#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char usn[20];
    char name[20];
    char dept[20];
    float marks;
};

struct Student *s; // Pointer to array
int c = 0;         // Count of students

void add() {
    s = realloc(s, (c + 1) * sizeof(struct Student));
    printf("Enter USN, Name, Dept, Marks: ");
    scanf("%s %s %s %f", s[c].usn, s[c].name, s[c].dept, &s[c].marks);
    c++;
}

void display() {
    if (c == 0) {
        printf("No records.\n");
        return;
    }
    printf("\nUSN\tName\tDept\tMarks\n");
    for (int i = 0; i < c; i++) {
        printf("%s\t%s\t%s\t%.2f\n", s[i].usn, s[i].name, s[i].dept, s[i].marks);
    }
}

void search() {
    char key[20];
    printf("Enter USN to search: ");
    scanf("%s", key);
    for (int i = 0; i < c; i++) {
        if (strcmp(s[i].usn, key) == 0) {
            printf("Found: %s\t%s\t%.2f\n", s[i].name, s[i].dept, s[i].marks);
            return;
        }
    }
    printf("Not Found.\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Add 2.Display 3.Search 4.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: exit(0);
        }
    }
    return 0;
}