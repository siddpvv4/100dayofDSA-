#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Queue structure
struct Queue {
    struct TreeNode* data[2000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear == 1999) return;
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct TreeNode* temp = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

int size(struct Queue* q) {
    if (isEmpty(q)) return 0;
    return q->rear - q->front + 1;
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        printf("[]");
        return;
    }

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    printf("[\n");

    while (!isEmpty(&q)) {
        int levelSize = size(&q);

        printf("  [");

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = dequeue(&q);

            printf("%d", curr->val);
            if (i < levelSize - 1) printf(", ");

            if (curr->left) enqueue(&q, curr->left);
            if (curr->right) enqueue(&q, curr->right);
        }

        printf("]\n");
    }

    printf("]\n");
}