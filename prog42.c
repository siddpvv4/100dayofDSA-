#include <stdio.h>
#include <stdlib.h>

// Node structure
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct ListNode* insertEnd(struct ListNode* head, int val) {
    struct ListNode* newNode = createNode(val);

    if (head == NULL)
        return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next; // store next
        curr->next = prev;     // reverse link
        prev = curr;           // move prev
        curr = nextNode;       // move curr
    }
    return prev;
}

// Main function
int main() {
    struct ListNode* head = NULL;
    int n, val;

    printf("How many nodes? ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    printf("\nOriginal List:\n");
    printList(head);

    head = reverseList(head);

    printf("\nReversed List:\n");
    printList(head);

    return 0;
}