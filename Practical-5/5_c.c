/* c) Implement DEqueue with following operations:
• InsertionAtRear() • InsertionAtFront()
• DeletionAtRear() • DeletionAtFront()
• isempty() • isfull() */

#include <stdio.h>
#define SIZE 5  // Maximum size of DEQueue

int deque[SIZE];
int front = -1, rear = -1;

// Function to check if DEQueue is empty
int isEmpty() {
    return (front == -1);
}

// Function to check if DEQueue is full
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

// Function to insert element at rear
void insertionAtRear(int element) {
    if (isFull()) {
        printf("DEQueue is FULL! Cannot insert %d at rear.\n", element);
    } else {
        if (front == -1) { // First element
            front = rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0; // Wrap around
        } else {
            rear++;
        }
        deque[rear] = element;
        printf("%d inserted at REAR.\n", element);
    }
}

// Function to insert element at front
void insertionAtFront(int element) {
    if (isFull()) {
        printf("DEQueue is FULL! Cannot insert %d at front.\n", element);
    } else {
        if (front == -1) { // First element
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1; // Wrap around
        } else {
            front--;
        }
        deque[front] = element;
        printf("%d inserted at FRONT.\n", element);
    }
}

// Function to delete element from front
void deletionAtFront() {
    if (isEmpty()) {
        printf("DEQueue is EMPTY! Cannot delete from front.\n");
    } else {
        printf("%d deleted from FRONT.\n", deque[front]);
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else if (front == SIZE - 1) {
            front = 0; // Wrap around
        } else {
            front++;
        }
    }
}

// Function to delete element from rear
void deletionAtRear() {
    if (isEmpty()) {
        printf("DEQueue is EMPTY! Cannot delete from rear.\n");
    } else {
        printf("%d deleted from REAR.\n", deque[rear]);
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else if (rear == 0) {
            rear = SIZE - 1; // Wrap around
        } else {
            rear--;
        }
    }
}

// Function to display DEQueue elements
void display() {
    if (isEmpty()) {
        printf("DEQueue is EMPTY!\n");
    } else {
        printf("DEQueue elements are: ");
        int i = front;
        while (1) {
            printf("%d ", deque[i]);
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
        printf("\n--- DEQUEUE OPERATIONS ---\n");
        printf("1. Insert at Rear\n2. Insert at Front\n3. Delete from Rear\n4. Delete from Front\n5. Display\n6. Check Empty\n7. Check Full\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertionAtRear(value);
                break;
            case 2:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertionAtFront(value);
                break;
            case 3:
                deletionAtRear();
                break;
            case 4:
                deletionAtFront();
                break;
            case 5:
                display();
                break;
            case 6:
                if (isEmpty())
                    printf("DEQueue is EMPTY.\n");
                else
                    printf("DEQueue is NOT EMPTY.\n");
                break;
            case 7:
                if (isFull())
                    printf("DEQueue is FULL.\n");
                else
                    printf("DEQueue is NOT FULL.\n");
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
