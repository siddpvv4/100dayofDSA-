#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Function to perform DFS
bool dfs(int node, int V, int adj[MAX][MAX], bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            // If not visited → DFS
            if (!visited[i] && dfs(i, V, adj, visited, recStack))
                return true;

            // If already in recursion stack → cycle
            if (recStack[i])
                return true;
        }
    }

    // Remove node from recursion stack
    recStack[node] = false;
    return false;
}

// Function to detect cycle
bool isCycle(int V, int adj[MAX][MAX]) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Directed graph
    }

    if (isCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
