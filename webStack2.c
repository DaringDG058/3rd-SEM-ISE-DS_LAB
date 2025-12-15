#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the stack

// This is the "Structure to represent the Stack"
struct Stack {
    int items[MAX]; // The Array (to store web page numbers)
    int top;        // The Index (to track the top page)
};

// Function to initialize the stack
void initStack(struct Stack *s) {
    s->top = -1; // -1 means the stack is empty
}

// Push Function (Visit new page)
void push(struct Stack *s) {
    int pageID;
    if (s->top == MAX - 1) {
        printf("Stack Overflow! History is full.\n");
    } else {
        printf("Enter Web Page ID: ");
        scanf("%d", &pageID);
        s->top++;                // Move top up
        s->items[s->top] = pageID; // Store data in the array inside the struct
        printf("Visited Page: %d\n", pageID);
    }
}

// Pop Function (Go Back)
void pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow! No history to go back to.\n");
    } else {
        printf("Going back from Page: %d\n", s->items[s->top]);
        s->top--; // Move top down
    }
}

// Display Function
void display(struct Stack *s) {
    if (s->top == -1) {
        printf("History is Empty.\n");
    } else {
        printf("Web History (Top to Bottom):\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->items[i]);
        }
    }
}

int main() {
    struct Stack s; // Create the structure variable
    initStack(&s);  // Initialize it
    
    int choice;
    while (1) {
        printf("\n1. Visit Page (Push)\n2. Go Back (Pop)\n3. Display History\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: push(&s); break;
            case 2: pop(&s); break;
            case 3: display(&s); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}