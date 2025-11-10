/*Write a program
b) To implement circular linked list with following operations:
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

    if (head == NULL) {
        head = newNode;
        head->next = head;  // circular link
    } else {
        struct Node* temp = head;
        while (temp->next != head)  // go to last node
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning\n", value);
}

// Insert at end
void InsertAtLast(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
    printf("Inserted %d at end\n", value);
}

// Insert after specified node
void InsertAfterSpecifiedNode(int key, int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        if (temp->data == key) {
            struct Node* newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Inserted %d after %d\n", value, key);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Node %d not found!\n", key);
}

// Delete at beginning
void DeleteAtFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {  // only one node
        printf("Deleted %d (last node)\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    struct Node* del = head;
    head = head->next;
    temp->next = head;
    printf("Deleted %d from beginning\n", del->data);
    free(del);
}

// Delete at end
void DeleteAtLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {  // only one node
        printf("Deleted %d (last node)\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != head)
        temp = temp->next;

    struct Node* del = temp->next;
    temp->next = head;
    printf("Deleted %d from end\n", del->data);
    free(del);
}

// Delete after specified node
void DeleteAfterSpecifiedNode(int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        if (temp->data == key) {
            if (temp->next == head) {
                printf("No node exists after %d\n", key);
                return;
            }
            struct Node* del = temp->next;
            temp->next = del->next;
            printf("Deleted %d after %d\n", del->data, key);
            free(del);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Node %d not found!\n", key);
}

// Traverse (Display)
void Traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main menu
int main() {
    int choice, value, key;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
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