/* b) Implement Circular Queue with following operations:
enqueue(), dequeue(), display(), isempty() and isfull() */

#include <stdio.h>
#define SIZE 5  // Define maximum size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to check if queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Function to insert element into circular queue
void enqueue(int element) {
    if (isFull()) {
        printf("Queue is FULL! Cannot enqueue %d\n", element);
    } else {
        if (front == -1)  // First element
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = element;
        printf("%d enqueued to queue\n", element);
    }
}

// Function to remove element from circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY! Cannot dequeue\n");
    } else {
        printf("%d dequeued from queue\n", queue[front]);
        if (front == rear) {  // Only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

// Function to display elements of the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Queue elements are: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;
    while (1) {
        printf("\n--- CIRCULAR QUEUE OPERATIONS ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Check Empty\n5. Check Full\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                if (isEmpty())
                    printf("Queue is EMPTY\n");
                else
                    printf("Queue is NOT EMPTY\n");
                break;
            case 5:
                if (isFull())
                    printf("Queue is FULL\n");
                else
                    printf("Queue is NOT FULL\n");
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
