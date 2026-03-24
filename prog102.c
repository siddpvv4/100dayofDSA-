#include <stdio.h>
#include <stdlib.h>

// Define structure (REQUIRED in VS Code)
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// LCA function
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL) {
        return root;
    }

    return (left != NULL) ? left : right;
}

// Helper: find node by value
struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;

    struct TreeNode* left = findNode(root->left, val);
    if (left != NULL) return left;

    return findNode(root->right, val);
}

int main() {
    /*
        Example Tree:
              3
             / \
            5   1
           / \ / \
          6  2 0  8
            / \
           7   4
    */

    struct TreeNode* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->right->left = createNode(0);
    root->right->right = createNode(8);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);

    int p_val = 5, q_val = 1;

    struct TreeNode* p = findNode(root, p_val);
    struct TreeNode* q = findNode(root, q_val);

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    printf("LCA of %d and %d is: %d\n", p_val, q_val, lca->val);

    return 0;
}