#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Create new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Add two numbers
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* temp = &dummy;
    
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        
        temp->next = createNode(sum % 10);
        temp = temp->next;
    }
    
    return dummy.next;
}

// Print list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n1, n2;
    
    scanf("%d", &n1);
    
    struct ListNode *l1 = NULL, *tail1 = NULL;
    
    for (int i = 0; i < n1; i++) {
        int val;
        scanf("%d", &val);
        
        struct ListNode* newNode = createNode(val);
        
        if (l1 == NULL) {
            l1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }
    
    scanf("%d", &n2);
    
    struct ListNode *l2 = NULL, *tail2 = NULL;
    
    for (int i = 0; i < n2; i++) {
        int val;
        scanf("%d", &val);
        
        struct ListNode* newNode = createNode(val);
        
        if (l2 == NULL) {
            l2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }
    
    struct ListNode* result = addTwoNumbers(l1, l2);
    
    printList(result);
    
    return 0;
}