#include <stdio.h>
#include <stdlib.h>

// Structure for dynamic array (list)
typedef struct {
    int *data;
    int size;
    int capacity;
} List;

// Initialize list
void initList(List *list) {
    list->capacity = 2;
    list->size = 0;
    list->data = (int*)malloc(list->capacity * sizeof(int));
}

// Add element to list
void addEdgeToList(List *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Create adjacency list
    List *adj = (List*)malloc(n * sizeof(List));

    // Initialize each list
    for (int i = 0; i < n; i++) {
        initList(&adj[i]);
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add edge u -> v
        addEdgeToList(&adj[u], v);

        // Uncomment below for UNDIRECTED graph
        addEdgeToList(&adj[v], u);
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < adj[i].size; j++) {
            printf("%d ", adj[i].data[j]);
        }
        printf("\n");
    }

    return 0;
}
