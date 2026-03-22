#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Search in BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root != NULL) {
        if (root->val == val) {
            return root;
        } else if (val < root->val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

// Preorder print (to show subtree)
void preorder(struct TreeNode* root) {
    if (root == NULL) return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

// Main function
int main() {
    struct TreeNode* root = NULL;
    int n, val, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter BST values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter value to search: ");
    scanf("%d", &val);

    struct TreeNode* result = searchBST(root, val);

    if (result == NULL) {
        printf("Output: []\n");
    } else {
        printf("Subtree (Preorder): ");
        preorder(result);
        printf("\n");
    }

    return 0;
}