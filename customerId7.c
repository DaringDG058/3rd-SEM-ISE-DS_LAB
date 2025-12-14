#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node *next;
};

struct Node *head = NULL;

void insert() {
    struct Node *newNode, *temp;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    printf("Enter Customer ID: ");
    scanf("%d", &newNode->id);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Customer Added.\n");
}

void delete() {
    struct Node *temp;
    if (head == NULL) {
        printf("No customers waiting.\n");
    } else {
        temp = head;
        head = head->next;
        printf("Billing Done for ID: %d\n", temp->id);
        free(temp);
    }
}

void display() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is Empty.\n");
    } else {
        temp = head;
        printf("Waiting Customers: ");
        while (temp != NULL) {
            printf("%d -> ", temp->id);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Add Customer 2.Billing Done 3.Display 4.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insert(); display(); break;
            case 2: delete(); display(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
    return 0;
}