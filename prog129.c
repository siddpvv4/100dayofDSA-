#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 2000

// Adjacency list
int adj[MAX][MAX];
int adjSize[MAX];

// DFS function to detect cycle
bool dfs(int node, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            return true; // cycle found
        }
    }

    recStack[node] = false;
    return false;
}

// Main function
bool canFinish(int numCourses, int prerequisites[][2], int size) {
    // Initialize adjacency list
    for (int i = 0; i < numCourses; i++)
        adjSize[i] = 0;

    // Build graph
    for (int i = 0; i < size; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
    }

    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    // Check for cycle in all components
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack))
                return false;
        }
    }

    return true;
}
