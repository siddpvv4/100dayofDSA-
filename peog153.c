#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// Structure for adjacency list
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

Node* adj[MAX];

// Min Heap structure
typedef struct {
    int vertex;
    int dist;
} HeapNode;

HeapNode heap[MAX];
int heapSize = 0;
int pos[MAX]; // Track positions in heap

// Swap heap nodes
void swap(int i, int j) {
    HeapNode temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;

    pos[heap[i].vertex] = i;
    pos[heap[j].vertex] = j;
}

// Heapify
void heapify(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heapSize && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < heapSize && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(idx, smallest);
        heapify(smallest);
    }
}

// Extract min
HeapNode extractMin() {
    HeapNode root = heap[0];
    heap[0] = heap[heapSize - 1];
    pos[heap[0].vertex] = 0;
    heapSize--;
    heapify(0);
    return root;
}

// Decrease key
void decreaseKey(int v, int dist) {
    int i = pos[v];
    heap[i].dist = dist;

    while (i && heap[i].dist < heap[(i - 1) / 2].dist) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

// Check if vertex is in heap
int isInHeap(int v) {
    return pos[v] < heapSize;
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra function
void dijkstra(int n, int src) {
    int dist[MAX];

    // Initialize
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        heap[i - 1].vertex = i;
        heap[i - 1].dist = INT_MAX;
        pos[i] = i - 1;
    }

    heapSize = n;

    // Source distance = 0
    dist[src] = 0;
    decreaseKey(src, 0);

    while (heapSize > 0) {
        HeapNode minNode = extractMin();
        int u = minNode.vertex;

        Node* temp = adj[u];

        while (temp) {
            int v = temp->vertex;

            if (isInHeap(v) && dist[u] != INT_MAX &&
                dist[u] + temp->weight < dist[v]) {

                dist[v] = dist[u] + temp->weight;
                decreaseKey(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

// Main
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize adjacency list
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(u, v, w);
        addEdge(v, u, w); // undirected graph
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}
