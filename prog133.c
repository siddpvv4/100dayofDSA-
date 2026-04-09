#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void kahnTopo(int n) {
    int i, j;
    int topo[MAX];
    int index = 0;

    // Initialize indegree to 0
    for(i = 0; i < n; i++)
        indegree[i] = 0;

    // Calculate indegree
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Add nodes with indegree 0 to queue
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            enqueue(i);
        }
    }

    // Process queue
    while(!isEmpty()) {
        int node = dequeue();
        topo[index++] = node;

        for(j = 0; j < n; j++) {
            if(adj[node][j] == 1) {
                indegree[j]--;
                if(indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }

    // Check for cycle
    if(index != n) {
        printf("Cycle exists! Topological sort not possible.\n");
        return;
    }

    // Print result
    printf("Topological Order: ");
    for(i = 0; i < n; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

int main() {
    int n, m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize adjacency matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed graph
    }

    kahnTopo(n);

    return 0;
}
