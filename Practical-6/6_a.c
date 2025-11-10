/*Write a program
a) To implement singly linked list with following operations:
• InsertAtFirst() • InsertAtLast() • InsertAfterspecifiednode()
• DeleteAtFirst() • DeleteAtLast() • DeleteAfterspecifiednode()
• Traverse() (Display)*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Head pointer (global)
struct Node* head = NULL;

// Function to create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void InsertAtFirst(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning\n", value);
}

// Insert at end
void InsertAtLast(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        printf("Inserted %d as first node\n", value);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    printf("Inserted %d at end\n", value);
}

// Insert after specified node
void InsertAfterSpecifiedNode(int key, int value) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node %d not found!\n", key);
        return;
    }

    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d after %d\n", value, key);
}

// Delete from beginning
void DeleteAtFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}

// Delete from end
void DeleteAtLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted %d (last node)\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    printf("Deleted %d from end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Delete after specified node
void DeleteAfterSpecifiedNode(int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("No node exists after %d\n", key);
        return;
    }

    struct Node* del = temp->next;
    temp->next = del->next;
    printf("Deleted %d after %d\n", del->data, key);
    free(del);
}

// Traverse (Display)
void Traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main menu
int main() {
    int choice, value, key;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
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