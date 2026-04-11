#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Relax edges k+1 times
    for(int i = 0; i <= k; i++) {
        vector<int> temp = dist;

        for(auto &f : flights) {
            int u = f[0], v = f[1], cost = f[2];

            if(dist[u] != INT_MAX && dist[u] + cost < temp[v]) {
                temp[v] = dist[u] + cost;
            }
        }

        dist = temp;
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
}
