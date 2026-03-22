struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Base case: not found or found
    if (root == NULL || root->val == val) {
        return root;
    }

    // Search in left subtree
    if (val < root->val) {
        return searchBST(root->left, val);
    }
    
    // Search in right subtree
    return searchBST(root->right, val);
}