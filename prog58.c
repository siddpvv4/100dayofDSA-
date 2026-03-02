#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Create node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Add two numbers (forward order, no reverse)
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    int stack1[100], stack2[100];
    int top1 = -1, top2 = -1;
    
    // Push l1 into stack1
    while (l1 != NULL) {
        stack1[++top1] = l1->val;
        l1 = l1->next;
    }
    
    // Push l2 into stack2
    while (l2 != NULL) {
        stack2[++top2] = l2->val;
        l2 = l2->next;
    }
    
    int carry = 0;
    struct ListNode* result = NULL;
    
    // Pop and add
    while (top1 >= 0 || top2 >= 0 || carry) {
        
        int sum = carry;
        
        if (top1 >= 0)
            sum += stack1[top1--];
            
        if (top2 >= 0)
            sum += stack2[top2--];
        
        carry = sum / 10;
        
        struct ListNode* newNode = createNode(sum % 10);
        
        // Insert at front
        newNode->next = result;
        result = newNode;
    }
    
    return result;
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