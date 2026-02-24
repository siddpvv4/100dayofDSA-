#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

// Insert at end
struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Remove all occurrences
struct Node* removeElements(struct Node* head, int val) {

    while (head != NULL && head->val == val) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    if (head == NULL)
        return NULL;

    struct Node* curr = head;

    while (curr->next != NULL) {
        if (curr->next->val == val) {
            struct Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }

    return head;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n, value, val;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    scanf("%d", &val);

    head = removeElements(head, val);

    printList(head);

    return 0;
}