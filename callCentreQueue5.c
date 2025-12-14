#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int q[MAX];   // The Array
int f = 0;    // Front
int r = -1;   // Rear

void add() {
    int id;
    if (r == MAX - 1) {
        printf("Queue Overflow!\n");
    } else {
        printf("Enter Call ID: ");
        scanf("%d", &id);
        r++;
        q[r] = id;
    }
}

void del() {
    if (f > r) {
        printf("Queue Underflow!\n");
        // Reset to save space
        f = 0; 
        r = -1;
    } else {
        printf("Serviced Call ID: %d\n", q[f]);
        f++;
    }
}

void display() {
    if (f > r) {
        printf("Queue is Empty.\n");
    } else {
        printf("Waiting: ");
        for (int i = f; i <= r; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Add 2.Service 3.Display 4.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: add(); break;
            case 2: del(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
    return 0;
}
