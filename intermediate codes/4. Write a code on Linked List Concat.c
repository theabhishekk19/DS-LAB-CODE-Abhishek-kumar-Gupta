#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL;
struct Node *head2 = NULL;

void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d → ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void concatenate() {
    if (head1 == NULL) {
        head1 = head2;
        head2 = NULL;
        printf("Concatenated successfully.\n");
        return;
    }

    struct Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    head2 = NULL;

    printf("Concatenated successfully.\n");
}

int main() {
    int n1, n2, value;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    printf("Enter elements for List 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        insertAtEnd(&head1, value);
    }

    printf("\nEnter number of elements in List 2: ");
    scanf("%d", &n2);
    printf("Enter elements for List 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        insertAtEnd(&head2, value);
    }

    printf("\nList 1 before concatenation:\n");
    display(head1);

    printf("List 2 before concatenation:\n");
    display(head2);

    concatenate();

    printf("\nList after concatenation:\n");
    display(head1);

    return 0;
}
