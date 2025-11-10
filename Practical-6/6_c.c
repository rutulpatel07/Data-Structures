// c) To implement doubly linked list with above functions.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Head pointer (global)
struct Node* head = NULL;

// Function to create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void InsertAtFirst(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning\n", value);
}

// Insert at end
void InsertAtLast(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at end\n", value);
}

// Insert after specified node
void InsertAfterSpecifiedNode(int key, int value) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            struct Node* newNode = createNode(value);
            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != NULL)
                temp->next->prev = newNode;

            temp->next = newNode;

            printf("Inserted %d after %d\n", value, key);
            return;
        }
        temp = temp->next;
    }
    printf("Node %d not found!\n", key);
}

// Delete at beginning
void DeleteAtFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* del = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted %d from beginning\n", del->data);
    free(del);
}

// Delete at end
void DeleteAtLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL; // only one node

    printf("Deleted %d from end\n", temp->data);
    free(temp);
}

// Delete after specified node
void DeleteAfterSpecifiedNode(int key) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key && temp->next != NULL) {
            struct Node* del = temp->next;
            temp->next = del->next;

            if (del->next != NULL)
                del->next->prev = temp;

            printf("Deleted %d after %d\n", del->data, key);
            free(del);
            return;
        }
        temp = temp->next;
    }
    printf("Node %d not found or no node exists after it!\n", key);
}

// Traverse (Display forward)
void Traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List (Forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main menu
int main() {
    int choice, value, key;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. InsertAtFirst\n2. InsertAtLast\n3. InsertAfterSpecifiedNode\n");
        printf("4. DeleteAtFirst\n5. DeleteAtLast\n6. DeleteAfterSpecifiedNode\n");
        printf("7. Traverse (Display)\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                InsertAtFirst(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                InsertAtLast(value);
                break;
            case 3:
                printf("Enter node value after which to insert: ");
                scanf("%d", &key);
                printf("Enter new value: ");
                scanf("%d", &value);
                InsertAfterSpecifiedNode(key, value);
                break;
            case 4:
                DeleteAtFirst();
                break;
            case 5:
                DeleteAtLast();
                break;
            case 6:
                printf("Enter node value after which to delete: ");
                scanf("%d", &key);
                DeleteAfterSpecifiedNode(key);
                break;
            case 7:
                Traverse();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}