#include <stdio.h>

#define MAX 100  

int list[MAX];
int size = 0;

void insert(int value);
void delete(int value);
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Array-based List Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void insert(int value) {
    if (size == MAX) {
        printf("List is full! Cannot insert.\n");
        return;
    }

    list[size] = value;
    size++;

    printf("Inserted %d into the list.\n", value);
}

void delete(int value) {
    if (size == 0) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    int index = -1;

    for (int i = 0; i < size; i++) {
        if (list[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    for (int i = index; i < size - 1; i++) {
        list[i] = list[i + 1];
    }

    size--;
    printf("Deleted %d from the list.\n", value);
}

void display() {
    if (size == 0) {
        printf("List is empty.\n");
        return;
    }

    printf("List elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}
