#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for BFS
struct QNode {
    struct Node* node;
    int hd;
};

struct Queue {
    int front, rear, size;
    struct QNode* arr;
};

struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = 0;
    q->size = n;
    q->arr = (struct QNode*)malloc(n * sizeof(struct QNode));
    return q;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build Tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Queue* q = createQueue(n);

    enqueue(q, root, 0);
    int i = 1;

    while (!isEmpty(q) && i < n) {
        struct QNode temp = dequeue(q);
        struct Node* curr = temp.node;

        // Left child
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(q, curr->left, 0);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(q, curr->right, 0);
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    // Map using array (HD range: -100 to +100)
    int map[201][100];   // store nodes
    int count[201] = {0};

    struct Queue* q = createQueue(1000);
    enqueue(q, root, 0);

    int min = 0, max = 0;

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);
        struct Node* curr = temp.node;
        int hd = temp.hd;

        int index = hd + 100;  // shift for negative index

        map[index][count[index]++] = curr->data;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (curr->left)
            enqueue(q, curr->left, hd - 1);

        if (curr->right)
            enqueue(q, curr->right, hd + 1);
    }

    // Print result
    for (int i = min; i <= max; i++) {
        int index = i + 100;
        for (int j = 0; j < count[index]; j++) {
            printf("%d ", map[index][j]);
        }
        printf("\n");
    }
}

// Driver Code
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}