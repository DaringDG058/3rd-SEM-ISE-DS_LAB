#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue() {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Customer ID: ");
    scanf("%d", &newNode->id);
    
    if (front == NULL) {
        front = newNode;
        rear = newNode;
        newNode->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("Customer %d added.\n", newNode->id);
}

void dequeue() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue Underflow (No customers).\n");
        return;
    }

    if (front == rear) {
        printf("Serviced Customer ID: %d\n", front->id);
        free(front);
        front = NULL;
        rear = NULL;
    } else {
        printf("Serviced Customer ID: %d\n", front->id);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display() {
    struct Node *temp = front;
    if (front == NULL) {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Waiting Customers: ");
    do {
        printf("%d -> ", temp->id);
        temp = temp->next;
    } while (temp != front); // Stop when we circle back to start
    printf("(Back to Start)\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Add Customer 2.Service Customer 3.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: enqueue(); display(); break;
            case 2: dequeue(); display(); break;
            case 3: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}