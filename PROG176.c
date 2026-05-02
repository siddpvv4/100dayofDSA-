#include <stdio.h>

// Function to check if we can ship within given days
int canShip(int weights[], int n, int days, int capacity) {
    int currentLoad = 0;
    int requiredDays = 1;

    for (int i = 0; i < n; i++) {
        if (currentLoad + weights[i] > capacity) {
            requiredDays++;
            currentLoad = 0;
        }
        currentLoad += weights[i];
    }

    return requiredDays <= days;
}

// Main function
int shipWithinDays(int weights[], int n, int days) {
    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (weights[i] > low) low = weights[i]; // max element
        high += weights[i]; // sum
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canShip(weights, n, days, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
