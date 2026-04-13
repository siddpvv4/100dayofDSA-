#include <stdio.h>
#include <limits.h>
#include <string.h>

int n;
int dp[1 << 15][15];

int min(int a, int b) {
    return a < b ? a : b;
}

int tsp(int mask, int pos, int cost[15][15]) {
    if (mask == (1 << n) - 1)
        return cost[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newCost = cost[pos][city] +
                          tsp(mask | (1 << city), city, cost);
            ans = min(ans, newCost);
        }
    }

    return dp[mask][pos] = ans;
}

int total_cost(int cost[15][15], int size) {
    n = size;
    memset(dp, -1, sizeof(dp));
    return tsp(1, 0, cost);
}
