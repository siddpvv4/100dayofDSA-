#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper to create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Recursive builder
struct TreeNode* build(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    // Pick current root
    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = createNode(rootVal);

    // If leaf node
    if (inStart == inEnd)
        return root;

    // Find root in inorder
    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    // IMPORTANT: build right first
    root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left  = build(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Main function
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return build(inorder, postorder, 0, inorderSize - 1, &postIndex);
}
