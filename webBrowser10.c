#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char url[50];
    struct node *next;
};

struct node *backStack = NULL;
struct node *forwardStack = NULL;
char currentPage[50] = "Home";

int isEmpty(struct node *top) {
    return top == NULL;
}

void push(struct node **top, char *url) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(temp->url, url);
    temp->next = *top;
    *top = temp;
}

void pop(struct node **top, char *buffer) {
    if (*top == NULL) {
        return;
    }
    struct node *temp = *top;
    strcpy(buffer, temp->url);
    *top = (*top)->next;
    free(temp);
}

void clearStack(struct node **top) {
    struct node *temp;
    while (*top != NULL) {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

void printStack(struct node *top) {
    if (top == NULL) {
        printf("Empty");
    }
    while (top != NULL) {
        printf("%s -> ", top->url);
        top = top->next;
    }
    printf("NULL\n");
}

void displayStatus() {
    printf("\n--- Browser State ---\n");
    printf("Back Stack:    "); printStack(backStack);
    printf("Current Page:  [%s]\n", currentPage);
    printf("Forward Stack: "); printStack(forwardStack);
    printf("---------------------\n");
}

void visitPage() {
    char newURL[50];
    printf("Enter URL to visit: ");
    scanf("%s", newURL);

    push(&backStack, currentPage);
    clearStack(&forwardStack);
    strcpy(currentPage, newURL);

    printf("Visiting: %s\n", currentPage);
    displayStatus();
}

void goBack() {
    if (isEmpty(backStack)) {
        printf("No previous page available (Back Stack Empty).\n");
        return;
    }

    push(&forwardStack, currentPage);
    pop(&backStack, currentPage);

    printf("Moved Back to: %s\n", currentPage);
    displayStatus();
}

void goForward() {
    if (isEmpty(forwardStack)) {
        printf("No forward page available (Forward Stack Empty).\n");
        return;
    }

    push(&backStack, currentPage);
    pop(&forwardStack, currentPage);

    printf("Moved Forward to: %s\n", currentPage);
    displayStatus();
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Visit New Page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: visitPage(); break;
            case 2: goBack(); break;
            case 3: goForward(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}