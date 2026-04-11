#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 101

int minDistance(int dist[], bool visited[], int n) {
    int min = INT_MAX, min_index = -1;

    for(int i = 1; i <= n; i++) {
        if(!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {

    int graph[MAX][MAX];

    // Initialize graph
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Fill edges
    for(int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        graph[u][v] = w;
    }

    int dist[MAX];
    bool visited[MAX];

    for(int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[k] = 0;

    // Dijkstra
    for(int i = 1; i <= n; i++) {
        int u = minDistance(dist, visited, n);
        if(u == -1) break;

        visited[u] = true;

        for(int v = 1; v <= n; v++) {
            if(!visited[v] && graph[u][v] != INT_MAX &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Find max distance
    int maxTime = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INT_MAX) return -1;
        if(dist[i] > maxTime) maxTime = dist[i];
    }

    return maxTime;
}
