#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create Node
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

// Build Tree
struct TreeNode* build(int* preorder, int* inorder, int start, int end, int* preIndex) {
    if (start > end) return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = createNode(rootVal);

    int mid = findIndex(inorder, start, end, rootVal);

    root->left = build(preorder, inorder, start, mid - 1, preIndex);
    root->right = build(preorder, inorder, mid + 1, end, preIndex);

    return root;
}

// Postorder Traversal (for checking)
void postorder(struct TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct TreeNode* root = build(preorder, inorder, 0, n - 1, &preIndex);

    // Output (postorder)
    postorder(root);

    return 0;
}  
