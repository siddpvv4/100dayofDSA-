#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// Adjacency list node
typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

// Graph
Node* adj[MAX];

// Min Heap Node
typedef struct {
    int vertex, dist;
} HeapNode;

// Min Heap
typedef struct {
    int size;
    HeapNode heap[MAX];
} MinHeap;

// Swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(MinHeap* h, int i) {
    while(i > 0 && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Heapify down
void heapifyDown(MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if(right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if(smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

// Push into heap
void push(MinHeap* h, int v, int dist) {
    h->heap[h->size].vertex = v;
    h->heap[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

// Pop min
HeapNode pop(MinHeap* h) {
    HeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) adj[i] = NULL;

    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int source;
    printf("Enter source: ");
    scanf("%d", &source);

    int dist[n];
    for(int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[source] = 0;

    MinHeap heap;
    heap.size = 0;

    push(&heap, source, 0);

    while(heap.size > 0) {
        HeapNode curr = pop(&heap);
        int u = curr.vertex;

        Node* temp = adj[u];
        while(temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Shortest distances from source %d:\n", source);
    for(int i = 0; i < n; i++) {
        if(dist[i] == INT_MAX)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }

    return 0;
}
