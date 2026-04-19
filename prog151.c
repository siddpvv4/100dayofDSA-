#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int time = 0;

void dfs(int u, int visited[], int disc[], int low[], int parent[],
         int ap[], int V, int** adj, int* adjSize) {
    
    visited[u] = 1;
    disc[u] = low[u] = ++time;
    int children = 0;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];

        // Ignore self-loop
        if (v == u) continue;

        if (!visited[v]) {
            children++;
            parent[v] = u;

            dfs(v, visited, disc, low, parent, ap, V, adj, adjSize);

            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            // Case 1: root node
            if (parent[u] == -1 && children > 1)
                ap[u] = 1;

            // Case 2: non-root
            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else if (v != parent[u]) {
            // Back edge
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
    }
}

int* articulationPoints(int V, int** adj, int* adjSize, int* returnSize) {

    int* visited = (int*)calloc(V, sizeof(int));
    int* disc = (int*)malloc(V * sizeof(int));
    int* low = (int*)malloc(V * sizeof(int));
    int* parent = (int*)malloc(V * sizeof(int));
    int* ap = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++)
        parent[i] = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, disc, low, parent, ap, V, adj, adjSize);
        }
    }

    // Count articulation points
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (ap[i]) count++;
    }

    if (count == 0) {
        int* res = (int*)malloc(sizeof(int));
        res[0] = -1;
        *returnSize = 1;
        return res;
    }

    int* res = (int*)malloc(count * sizeof(int));
    int idx = 0;

    for (int i = 0; i < V; i++) {
        if (ap[i])
            res[idx++] = i;
    }

    *returnSize = count;
    return res;
}
