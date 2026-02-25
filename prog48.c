#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to detect cycle start
struct ListNode *detectCycle(struct ListNode *head) {

    if (head == NULL || head->next == NULL)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {

            struct ListNode *ptr = head;

            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return NULL;
}

// helper to create node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {

    // Creating list: 3 -> 2 -> 0 -> -4
    struct ListNode* head = newNode(3);
    head->next = newNode(2);
    head->next->next = newNode(0);
    head->next->next->next = newNode(-4);

    // Creating cycle: tail connects to node with value 2
    head->next->next->next->next = head->next;

    struct ListNode* ans = detectCycle(head);

    if (ans != NULL)
        printf("Cycle starts at node value: %d\n", ans->val);
    else
        printf("No cycle\n");

    return 0;
}