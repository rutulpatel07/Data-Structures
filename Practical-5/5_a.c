/* Implementation of various types of Queues
a) Implement Simple Queue with following operations:
enqueue(), dequeue(), display(), isempty() and isfull()*/

#include <stdio.h>
#define SIZE 5  // Define maximum size of queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Function to check if queue is full
int isFull() {
    return (rear == SIZE - 1);
}

// Function to insert element into queue
void enqueue(int element) {
    if (isFull()) {
        printf("Queue is FULL! Cannot enqueue %d\n", element);
    } else {
        if (front == -1)  // first element
            front = 0;
        rear++;
        queue[rear] = element;
        printf("%d enqueued to queue\n", element);
    }
}

// Function to remove element from queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY! Cannot dequeue\n");
    } else {
        printf("%d dequeued from queue\n", queue[front]);
        front++;
        if (front > rear)  // reset queue when last element removed
            front = rear = -1;
    }
}

// Function to display elements of queue
void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;
    while (1) {
        printf("\n--- SIMPLE QUEUE OPERATIONS ---\n");
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
