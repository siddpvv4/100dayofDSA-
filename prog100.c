struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        // If both nodes are smaller, go left
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        // If both nodes are greater, go right
        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        // Split point found → this is LCA
        else {
            return root;
        }
    }
    return NULL;
}