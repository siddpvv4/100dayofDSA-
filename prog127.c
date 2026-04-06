#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100005

// Adjacency list
int* adj[MAX];
int size[MAX];
bool visited[MAX];

// Add edge
void addEdge(int u, int v) {
    adj[u] = (int*)realloc(adj[u], (size[u] + 1) * sizeof(int));
    adj[u][size[u]++] = v;

    adj[v] = (int*)realloc(adj[v], (size[v] + 1) * sizeof(int));
    adj[v][size[v]++] = u;
}

// DFS function
bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return true;
        }
        else if (neighbor != parent) {
            // Cycle detected
            return true;
        }
    }
    return false;
}

// Function to check cycle
bool hasCycle(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 4, E = 4;

    int edges[][2] = {
        {0, 1}, {0, 2}, {1, 2}, {2, 3}
    };

    // Initialize
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        size[i] = 0;
        visited[i] = false;
    }

    // Build graph
    for (int i = 0; i < E; i++) {
        addEdge(edges[i][0], edges[i][1]);
    }

    if (hasCycle(V))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
