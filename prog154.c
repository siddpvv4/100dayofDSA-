#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int *adj[MAX], *transpose[MAX];
int adjSize[MAX], transSize[MAX];
int visited[MAX];
int stack[MAX], top = -1;

void dfs1(int node) {
    visited[node] = 1;
    for (int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            dfs1(next);
        }
    }
    stack[++top] = node;
}

void dfs2(int node) {
    visited[node] = 1;
    for (int i = 0; i < transSize[node]; i++) {
        int next = transpose[node][i];
        if (!visited[next]) {
            dfs2(next);
        }
    }
}

int kosaraju(int V) {
    // Step 1: First DFS
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    // Reset visited
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    int scc = 0;

    // Step 2: Process stack
    while (top >= 0) {
        int node = stack[top--];

        if (!visited[node]) {
            scc++;
            dfs2(node);
        }
    }

    return scc;
}

int main() {
    int V = 5, E = 5;
    int edges[5][2] = {{0,2},{0,3},{1,0},{2,1},{3,4}};

    // Initialize
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(E * sizeof(int));
        transpose[i] = (int*)malloc(E * sizeof(int));
        adjSize[i] = transSize[i] = 0;
        visited[i] = 0;
    }

    // Build graph
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        transpose[v][transSize[v]++] = u;
    }

    printf("%d\n", kosaraju(V));  // Output: 3

    return 0;
}
