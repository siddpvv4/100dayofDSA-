#include <limits.h>
#include <stdlib.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;

    int* minDist = (int*)malloc(n * sizeof(int));
    int* inMST = (int*)malloc(n * sizeof(int));

    // Initialize
    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
        inMST[i] = 0;
    }

    minDist[0] = 0;
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        // Pick minimum distance vertex not in MST
        for (int j = 0; j < n; j++) {
            if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        inMST[u] = 1;
        totalCost += minDist[u];

        // Update distances
        for (int v = 0; v < n; v++) {
            if (!inMST[v]) {
                int dist = abs(points[u][0] - points[v][0]) +
                           abs(points[u][1] - points[v][1]);

                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(minDist);
    free(inMST);

    return totalCost;
}
