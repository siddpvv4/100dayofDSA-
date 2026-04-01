#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int cameras = 0;

// DFS function
int dfs(struct TreeNode* root) {
    if (root == NULL)
        return 1; // NULL nodes are covered

    int left = dfs(root->left);
    int right = dfs(root->right);

    // If any child is not covered
    if (left == -1 || right == -1) {
        cameras++;
        return 0; // Place camera here
    }

    // If any child has camera
    if (left == 0 || right == 0)
        return 1; // Covered

    return -1; // Not covered
}

// Main function to calculate minimum cameras
int minCameraCover(struct TreeNode* root) {
    if (dfs(root) == -1)
        cameras++; // Root needs camera

    return cameras;
}
