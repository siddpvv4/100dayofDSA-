#include <stdio.h>

#define MAX 200

// DFS function
void dfs(int isConnected[MAX][MAX], int n, int city, int visited[]) {
    visited[city] = 1;

    for (int j = 0; j < n; j++) {
        if (isConnected[city][j] == 1 && visited[j] == 0) {
            dfs(isConnected, n, j, visited);
        }
    }
}

// Function to find number of provinces
int findProvinces(int isConnected[MAX][MAX], int n) {
    int visited[MAX] = {0};
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(isConnected, n, i, visited);
            provinces++;
        }
    }

    return provinces;
}

int main() {
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    int isConnected[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    int result = findProvinces(isConnected, n);

    printf("Number of Provinces: %d\n", result);

    return 0;
}
