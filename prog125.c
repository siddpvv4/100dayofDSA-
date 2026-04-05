#include <stdio.h>

#define MAX 100

typedef struct {
    int x, y;
} Pair;

int orangesRotting(int grid[10][10], int m, int n) {
    Pair queue[MAX];
    int front = 0, rear = 0;

    int fresh = 0;

    // Step 1: Push all rotten oranges into queue & count fresh
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Pair){i, j};
            }
            else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // If no fresh oranges
    if (fresh == 0) return 0;

    int minutes = -1;

    int directions[4][2] = {
        {0,1}, {1,0}, {0,-1}, {-1,0}
    };

    // BFS
    while (front < rear) {
        int size = rear - front;
        minutes++;

        for (int i = 0; i < size; i++) {
            Pair current = queue[front++];

            for (int d = 0; d < 4; d++) {
                int nx = current.x + directions[d][0];
                int ny = current.y + directions[d][1];

                // Check bounds and fresh orange
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;  // rot it
                    queue[rear++] = (Pair){nx, ny};
                    fresh--;
                }
            }
        }
    }

    return (fresh == 0) ? minutes : -1;
}

int main() {
    int grid[10][10] = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int m = 3, n = 3;

    int result = orangesRotting(grid, m, n);
    printf("%d\n", result);  // Output: 4

    return 0;
}
