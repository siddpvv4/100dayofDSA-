// Definition for a Node
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

// Helper function for DFS
struct Node* dfs(struct Node* node, struct Node** visited) {
    if (!node) return NULL;

    // If already cloned, return it
    if (visited[node->val] != NULL) {
        return visited[node->val];
    }

    // Create new node
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));

    // Mark as visited
    visited[node->val] = clone;

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i], visited);
    }

    return clone;
}

// Main function
struct Node* cloneGraph(struct Node* s) {
    if (!s) return NULL;

    // Since values are 1 to 100
    struct Node* visited[101] = {NULL};

    return dfs(s, visited);
}
