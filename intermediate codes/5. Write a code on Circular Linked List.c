#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning.\n", value);
}

void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
    printf("Inserted %d at end.\n", value);
}


void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        printf("Deleted %d.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head, *last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        printf("Deleted %d.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head, *prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
}

void deleteByValue(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    if (head->data == key) {
        deleteBeginning();
        return;
    }

    do {
        prev = temp;
        temp = temp->next;

        if (temp->data == key) {
            prev->next = temp->next;
            printf("Deleted %d.\n", key);
            free(temp);
            return;
        }

    } while (temp != head);

    printf("Value %d not found.\n", key);
}


void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d → ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}


int main() {
    int choice, value, key;

    while (1) {
        printf("\n----- CIRCULAR LINKED LIST MENU -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Beginning\n");
        printf("4. Delete End\n");
        printf("5. Delete by Value\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;

        case 3:
            deleteBeginning();
            break;

        case 4:
            deleteEnd();
            break;

        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &key);
            deleteByValue(key);
            break;

        case 6:
            display();
            break;

        case 7:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
