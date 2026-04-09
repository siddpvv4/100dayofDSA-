#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

// Queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(Queue* q, int val) {
    q->items[q->rear++] = val;
}

int dequeue(Queue* q) {
    return q->items[q->front++];
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

char* alienOrder(char words[][100], int n) {
    int graph[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int present[MAX] = {0};

    // Mark all characters present
    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    // Build graph
    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];
        int len1 = strlen(w1), len2 = strlen(w2);
        int found = 0;

        for (int j = 0; j < len1 && j < len2; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                if (!graph[u][v]) {
                    graph[u][v] = 1;
                    indegree[v]++;
                }
                found = 1;
                break;
            }
        }

        // Invalid case: prefix issue
        if (!found && len1 > len2) {
            return "";
        }
    }

    // Kahn’s Algorithm
    Queue q;
    initQueue(&q);

    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    char* result = (char*)malloc(27 * sizeof(char));
    int idx = 0;

    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        result[idx++] = u + 'a';

        for (int v = 0; v < MAX; v++) {
            if (graph[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(&q, v);
                }
            }
        }
    }

    result[idx] = '\0';

    // Check for cycle
    int totalChars = 0;
    for (int i = 0; i < MAX; i++) {
        if (present[i]) totalChars++;
    }

    if (idx < totalChars) return "";

    return result;
}
