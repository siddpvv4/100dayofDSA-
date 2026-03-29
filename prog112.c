#include <stdio.h>
#include <stdlib.h>

// Define TreeNode for local execution
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to flatten tree
void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left != NULL) {
            struct TreeNode* prev = curr->left;

            while (prev->right != NULL) {
                prev = prev->right;
            }

            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}

// Helper to create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Print flattened list
void printList(struct TreeNode* root) {
    while (root != NULL) {
        printf("%d ", root->val);
        root = root->right;
    }
}

int main() {
    // Example: [1,2,5,3,4,null,6]
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    flatten(root);

    printList(root);  // Output: 1 2 3 4 5 6

    return 0;
}
