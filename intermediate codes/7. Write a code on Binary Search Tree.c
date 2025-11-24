#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node* createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        printf("Value %d already exists in the BST. Ignoring duplicate.\n", value);
    }

    return root;
}


struct Node* findMin(struct Node *root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}


struct Node* deleteNode(struct Node *root, int value) {
    if (root == NULL) {
        printf("Value %d not found in the tree.\n", value);
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            printf("Deleting leaf node %d\n", root->data);
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            struct Node *temp = root->right;
            printf("Deleting node %d with one child\n", root->data);
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            printf("Deleting node %d with one child\n", root->data);
            free(root);
            return temp;
        }
        else {
            struct Node *temp = findMin(root->right);
            printf("Deleting node %d with two children (replacing with %d)\n",
                   root->data, temp->data);
            root->data = temp->data;  
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorder(struct Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main() {
    struct Node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n------ BINARY SEARCH TREE MENU ------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;

        case 3:
            printf("Inorder Traversal (sorted): ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
