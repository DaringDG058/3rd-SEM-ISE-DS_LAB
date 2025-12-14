#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int expo;
    struct Node *next;
};

void insert(struct Node **head, int c, int e) {
    struct Node *newNode, *temp;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->expo = e;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node* add(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->expo > p2->expo) {
            insert(&result, p1->coeff, p1->expo);
            p1 = p1->next;
        } 
        else if (p2->expo > p1->expo) {
            insert(&result, p2->coeff, p2->expo);
            p2 = p2->next;
        } 
        else { // Exponents are equal, add coefficients
            insert(&result, p1->coeff + p2->coeff, p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insert(&result, p1->coeff, p1->expo);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insert(&result, p2->coeff, p2->expo);
        p2 = p2->next;
    }
    return result;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->expo);
        if (head->next != NULL) printf(" + ");
        head = head->next;
    }
    printf("\n");
}

void readPoly(struct Node **poly) {
    int n, c, e;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter Coeff and Expo for term %d: ", i + 1);
        scanf("%d %d", &c, &e);
        insert(poly, c, e);
    }
}

int main() {
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *sum = NULL;

    printf("--- Polynomial 1 ---\n");
    readPoly(&poly1);

    printf("\n--- Polynomial 2 ---\n");
    readPoly(&poly2);

    // Perform Addition
    sum = add(poly1, poly2);

    printf("\nPolynomial 1: "); display(poly1);
    printf("Polynomial 2: "); display(poly2);
    printf("Result Sum:   "); display(sum);

    return 0;
}
