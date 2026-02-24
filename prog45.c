#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at end
struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    // Traverse to last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Function to delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {

    // Case 1: Empty list
    if (head == NULL)
        return head;

    struct Node *temp = head, *prev = NULL;

    // Case 2: Key is in head
    if (temp->data == key) {
        head = temp->next;   // Move head
        free(temp);          // Free memory
        return head;
    }

    // Case 3: Key in middle or end
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Key not found
    if (temp == NULL)
        return head;

    // Remove node
    prev->next = temp->next;
    free(temp);

    return head;
}

// Function to print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {

    int n, value, key;
    struct Node* head = NULL;

    // Input n
    scanf("%d", &n);

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    // Input key
    scanf("%d", &key);

    // Delete key
    head = deleteKey(head, key);

    // Output list
    printList(head);

    return 0;
}