#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// insert at end
struct Node* insertEnd(struct Node* head, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// find middle node (slow-fast pointer)
struct Node* middleNode(struct Node* head)
{
    struct Node* slow = head;
    struct Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;  // middle node
}

// print from given node
void printFromNode(struct Node* node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    int n, value;
    struct Node* head = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    struct Node* mid = middleNode(head);
    printFromNode(mid);

    return 0;
}