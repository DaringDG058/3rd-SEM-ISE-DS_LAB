#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push() {
    int page;
    if (top == MAX - 1) {
        printf("History Full (Overflow)!\n");
    } else {
        printf("Enter Page Number: ");
        scanf("%d", &page);
        top++;
        stack[top] = page;
        printf("Visited Page: %d\n", page);
    }
}

void pop() {
    if (top == -1) {
        printf("No History (Underflow)!\n");
    } else {
        printf("Going back from Page: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("History is Empty.\n");
    } else {
        printf("Web History: \n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Visit 2.Back 3.History 4.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
    return 0;
}
