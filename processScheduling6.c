#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int q[MAX];
int f = -1, r = -1;

void add() {
    int pid;
    if ((r + 1) % MAX == f) {
        printf("Queue Overflow!\n");
    } else {
        printf("Enter Process ID: ");
        scanf("%d", &pid);
        
        if (f == -1) f = 0;
        
        r = (r + 1) % MAX;
        q[r] = pid;
    }
}

void del() {
    if (f == -1) {
        printf("Queue Underflow!\n");
    } else {
        printf("Removed Process ID: %d\n", q[f]);
        
        if (f == r) {
            f = -1;
            r = -1;
        } else {
            f = (f + 1) % MAX;
        }
    }
}

void display() {
    int i;
    if (f == -1) {
        printf("No processes.\n");
    } else {
        printf("Active Processes: ");
        for (i = f; i != r; i = (i + 1) % MAX) {
            printf("%d ", q[i]);
        }
        printf("%d\n", q[i]);
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Add Process 2.Remove Process 3.Display 4.Exit: ");
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
