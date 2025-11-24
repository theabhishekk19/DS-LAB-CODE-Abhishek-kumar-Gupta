#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};



struct Node *top = NULL;

void push(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto stack.\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    struct Node *temp = top;
    printf("Popped %d from stack.\n", temp->data);
    top = top->next;
    free(temp);
}

void displayStack() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* ---------- QUEUE USING LINKED LIST ---------- */

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d into queue.\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Dequeued %d from queue.\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;  
    }
    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue (front to rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



struct Node *frontC = NULL;
struct Node *rearC = NULL;

void cenqueue(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;

    if (frontC == NULL) {
        frontC = rearC = newNode;
        newNode->next = frontC;       
    } else {
        newNode->next = frontC;
        rearC->next = newNode;
        rearC = newNode;
    }
    printf("Enqueued %d into circular queue.\n", value);
}

void cdequeue() {
    if (frontC == NULL) {
        printf("Circular Queue Underflow! Queue is empty.\n");
        return;
    }

    struct Node *temp = frontC;

    if (frontC == rearC) {
        printf("Dequeued %d from circular queue.\n", temp->data);
        frontC = rearC = NULL;
        free(temp);
    } else {
        printf("Dequeued %d from circular queue.\n", temp->data);
        frontC = frontC->next;
        rearC->next = frontC;    
        free(temp);
    }
}

void displayCQueue() {
    if (frontC == NULL) {
        printf("Circular queue is empty.\n");
        return;
    }

    struct Node *temp = frontC;
    printf("Circular Queue (front to rear): ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != frontC);
    printf("(back to front)\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n========== MAIN MENU ==========\n");
        printf(" 1. Push (Stack - Linked List)\n");
        printf(" 2. Pop (Stack - Linked List)\n");
        printf(" 3. Display Stack\n");
        printf(" 4. Enqueue (Queue - Linked List)\n");
        printf(" 5. Dequeue (Queue - Linked List)\n");
        printf(" 6. Display Queue\n");
        printf(" 7. Enqueue (Circular Queue - Linked List)\n");
        printf(" 8. Dequeue (Circular Queue - Linked List)\n");
        printf(" 9. Display Circular Queue\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            displayStack();
            break;

        case 4:
            printf("Enter value to enqueue (queue): ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 5:
            dequeue();
            break;

        case 6:
            displayQueue();
            break;

        case 7:
            printf("Enter value to enqueue (circular queue): ");
            scanf("%d", &value);
            cenqueue(value);
            break;

        case 8:
            cdequeue();
            break;

        case 9:
            displayCQueue();
            break;

        case 10:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
