#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structure
struct ListNode {
    int val;
    struct ListNode* next;
};

// Reverse linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

// Check palindrome
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    // Find middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode* secondHalf = reverseList(slow);
    struct ListNode* firstHalf = head;

    // Compare both halves
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    struct ListNode *head = NULL, *temp = NULL, *newNode = NULL;

    // Create linked list
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Check palindrome
    if (isPalindrome(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}