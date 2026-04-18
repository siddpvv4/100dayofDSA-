#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int adj[MAX][MAX], adjSize[MAX];
int disc[MAX], low[MAX];
int time = 0;

void dfs(int u, int parent, int n) {
    disc[u] = low[u] = time++;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];

        if (v == parent) continue;

        if (disc[v] == -1) {
            dfs(v, u, n);
            low[u] = low[u] < low[v] ? low[u] : low[v];

            if (low[v] > disc[u]) {
                printf("[%d, %d]\n", u, v);
            }
        } else {
            low[u] = low[u] < disc[v] ? low[u] : disc[v];
        }
    }
}

int main() {
    int n = 4;
    int connections[][2] = {{0,1},{1,2},{2,0},{1,3}};
    int m = 4;

    // Build graph
    for (int i = 0; i < m; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // Initialize
    for (int i = 0; i < n; i++) {
        disc[i] = -1;
    }

    dfs(0, -1, n);

    return 0;
}A
