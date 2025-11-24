#include <stdio.h>
#include <stdlib.h>

#define MAX 100


int stack[MAX];
int top = -1;

int isStackFull() {
    return top == MAX - 1;
}

int isStackEmpty() {
    return top == -1;
}

void push(int item) {
    if (isStackFull()) {
        printf("Stack Overflow! Cannot push %d\n", item);
        return;
    }
    stack[++top] = item;
    printf("Pushed %d onto stack.\n", item);
}

int pop() {
    if (isStackEmpty()) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    printf("Popped %d from stack.\n", stack[top]);
    return stack[top--];
}

void peek() {
    if (isStackEmpty()) {
        printf("Stack is empty. No top element.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void displayStack() {
    if (isStackEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}


int queue[MAX];
int front = 0;
int rear = -1;

int isQueueFull() {
    return rear == MAX - 1;
}

int isQueueEmpty() {
    return front > rear;
}

void enqueue(int item) {
    if (isQueueFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", item);
        return;
    }
    queue[++rear] = item;
    printf("Enqueued %d into linear queue.\n", item);
}

int dequeue() {
    if (isQueueEmpty()) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return -1;
    }
    printf("Dequeued %d from linear queue.\n", queue[front]);
    return queue[front++];
}

void displayQueue() {
    if (isQueueEmpty()) {
        printf("Linear queue is empty.\n");
        return;
    }
    printf("Linear Queue (front to rear): ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


int cqueue[MAX];
int cfront = -1;
int crear = -1;

int isCQueueFull() {
    return ( (cfront == 0 && crear == MAX - 1) || (cfront == (crear + 1) % MAX) );
}

int isCQueueEmpty() {
    return cfront == -1;
}

void cenqueue(int item) {
    if (isCQueueFull()) {
        printf("Circular Queue Overflow! Cannot enqueue %d\n", item);
        return;
    }

    if (isCQueueEmpty()) {
        cfront = 0;
        crear = 0;
    } else {
        crear = (crear + 1) % MAX;
    }

    cqueue[crear] = item;
    printf("Enqueued %d into circular queue.\n", item);
}

int cdequeue() {
    int item;
    if (isCQueueEmpty()) {
        printf("Circular Queue Underflow! Cannot dequeue.\n");
        return -1;
    }

    item = cqueue[cfront];

    if (cfront == crear) {
        cfront = -1;
        crear = -1;
    } else {
        cfront = (cfront + 1) % MAX;
    }

    printf("Dequeued %d from circular queue.\n", item);
    return item;
}

void displayCQueue() {
    if (isCQueueEmpty()) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Circular Queue (front to rear): ");
    int i = cfront;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == crear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}


int main() {
    int choice, item;

    while (1) {
        printf("\n=========== MENU ===========\n");
        printf(" 1. Push (Stack)\n");
        printf(" 2. Pop (Stack)\n");
        printf(" 3. Peek (Stack)\n");
        printf(" 4. Display Stack\n");
        printf(" 5. Enqueue (Linear Queue)\n");
        printf(" 6. Dequeue (Linear Queue)\n");
        printf(" 7. Display Linear Queue\n");
        printf(" 8. Enqueue (Circular Queue)\n");
        printf(" 9. Dequeue (Circular Queue)\n");
        printf("10. Display Circular Queue\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            displayStack();
            break;
        case 5:
            printf("Enter element to enqueue (linear queue): ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 6:
            dequeue();
            break;
        case 7:
            displayQueue();
            break;
        case 8:
            printf("Enter element to enqueue (circular queue): ");
            scanf("%d", &item);
            cenqueue(item);
            break;
        case 9:
            cdequeue();
            break;
        case 10:
            displayCQueue();
            break;
        case 11:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
