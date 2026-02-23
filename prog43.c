#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node using dynamic memory allocation
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
// We use double pointers to modify the actual head and tail pointers
void insertNode(struct Node** head, struct Node** tail, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    // A dummy node makes handling the head of the merged list easier
    struct Node dummy;
    dummy.data = 0;
    dummy.next = NULL;
    struct Node* tail = &dummy;
    
    // Traverse both lists and attach the smaller node to the merged list
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    
    // If there are remaining nodes in either list, attach them
    if (head1 != NULL) {
        tail->next = head1;
    } else if (head2 != NULL) {
        tail->next = head2;
    }
    
    return dummy.next;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf(" ");
        }
        head = head->next;
    }
    printf("\n");
}

// Function to free allocated memory to prevent memory leaks
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, m, val;
    
    // Read first linked list
    if (scanf("%d", &n) != 1) return 0;
    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        insertNode(&head1, &tail1, val);
    }
    
    // Read second linked list
    if (scanf("%d", &m) != 1) return 0;
    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &val);
        insertNode(&head2, &tail2, val);
    }
    
    // Merge the two lists
    struct Node* mergedHead = mergeLists(head1, head2);
    
    // Print the result
    printList(mergedHead);
    
    // Clean up dynamic memory
    freeList(mergedHead);
    
    return 0;
}