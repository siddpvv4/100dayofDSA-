#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];

// DFS function to detect cycle
bool dfs(int node, int parent, int n) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {  // if edge exists
            if (!visited[i]) {
                if (dfs(i, node, n))
                    return true;
            }
            else if (i != parent) {
                // visited node not equal to parent → cycle
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    // check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
