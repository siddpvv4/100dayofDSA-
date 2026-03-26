#include <stdio.h>
#include <stdlib.h>

// Define TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Zigzag traversal
void zigzagLevelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int level = 0;

    while (front < rear) {
        int size = rear - front;
        int arr[size];

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            int index = (level % 2 == 0) ? i : (size - 1 - i);
            arr[index] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        // Print current level
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }

        level++;
    }
}

// Driver code
int main() {
    /*
        Example tree:
              3
             / \
            9  20
              /  \
             15   7
    */

    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Zigzag Traversal:\n");
    zigzagLevelOrder(root);

    return 0;
}