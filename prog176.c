#include <stdio.h>

// Function to check if we can split into <= k subarrays
int canSplit(int nums[], int n, int k, int maxSum) {
    int subarrays = 1;
    long long currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + nums[i] <= maxSum) {
            currentSum += nums[i];
        } else {
            subarrays++;
            currentSum = nums[i];
        }
    }

    return subarrays <= k;
}

int splitArray(int nums[], int n, int k) {
    int low = nums[0];
    long long high = 0;

    // Find max element and total sum
    for (int i = 0; i < n; i++) {
        if (nums[i] > low)
            low = nums[i];
        high += nums[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canSplit(nums, n, k, mid)) {
            ans = mid;
            high = mid - 1; // try smaller max sum
        } else {
            low = mid + 1;  // increase limit
        }
    }

    return ans;
}

// Driver code
int main() {
    int nums[] = {7, 2, 5, 10, 8};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    int result = splitArray(nums, n, k);
    printf("Minimum largest sum: %d\n", result);

    return 0;
}
