#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node *left;
    struct Node *right;
};

struct Node* insert(struct Node *root, int id) {
    if (root == NULL) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->id = id;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if (id < root->id) {
        root->left = insert(root->left, id);
    } else {
        root->right = insert(root->right, id);
    }
    return root;
}

// Preorder Traversal (Root -> Left -> Right)
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->id);
        preorder(root->left);
        preorder(root->right);
    }
}

// Find Largest ID (Rightmost Node)
void findMax(struct Node *root) {
    if (root == NULL) {
        printf("Database is Empty.\n");
        return;
    }
    
    struct Node *temp = root;
    // Keep going right to find the biggest number
    while (temp->right != NULL) {
        temp = temp->right;
    }
    printf("Largest Image ID: %d\n", temp->id);
}

int main() {
    struct Node *root = NULL;
    int ch, id;

    while (1) {
        printf("\n1.Insert Image ID 2.Display (Preorder) 3.Find Max ID 4.Exit: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter Image ID: ");
                scanf("%d", &id);
                root = insert(root, id);
                break;
            case 2:
                printf("Indexed Images: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                findMax(root);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
