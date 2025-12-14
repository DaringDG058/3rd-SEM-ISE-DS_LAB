#include <stdio.h>
#include <stdlib.h>

struct Node {
    int fileID;
    int size;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insert() {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter File ID and Size: ");
    scanf("%d %d", &newNode->fileID, &newNode->size);
    
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("File Added to Memory.\n");
}

void delete() {
    int pos, i;
    struct Node *temp = head;

    if (head == NULL) {
        printf("Memory is Empty.\n");
        return;
    }

    printf("Enter Position to delete (1, 2...): ");
    scanf("%d", &pos);

    // Case 1: Delete Head
    if (pos == 1) {
        head = head->next;
        if (head != NULL) head->prev = NULL;
        free(temp);
        printf("File Deleted.\n");
        return;
    }

    // Case 2: Traverse to position
    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid Position!\n");
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
        printf("File Deleted.\n");
    }
}

void display() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("No files in memory.\n");
        return;
    }
    printf("\nFile ID\tSize\n");
    while (temp != NULL) {
        printf("%d\t%d KB\n", temp->fileID, temp->size);
        temp = temp->next;
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Add File 2.Delete File 3.Display 4.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
    return 0;
}
