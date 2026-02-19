#include <stdio.h>
#include <limits.h>

// Kadane for Maximum Subarray
int kadaneMax(int arr[], int n) {
    int maxEnd = arr[0];
    int maxSoFar = arr[0];

    for(int i = 1; i < n; i++) {
        if(maxEnd + arr[i] > arr[i])
            maxEnd = maxEnd + arr[i];
        else
            maxEnd = arr[i];

        if(maxEnd > maxSoFar)
            maxSoFar = maxEnd;
    }
    return maxSoFar;
}

// Kadane for Minimum Subarray
int kadaneMin(int arr[], int n) {
    int minEnd = arr[0];
    int minSoFar = arr[0];

    for(int i = 1; i < n; i++) {
        if(minEnd + arr[i] < arr[i])
            minEnd = minEnd + arr[i];
        else
            minEnd = arr[i];

        if(minEnd < minSoFar)
            minSoFar = minEnd;
    }
    return minSoFar;
}

int maxCircularSum(int arr[], int n) {

    int totalSum = 0;
    for(int i = 0; i < n; i++)
        totalSum += arr[i];

    int maxSubarray = kadaneMax(arr, n);
    int minSubarray = kadaneMin(arr, n);

    // All elements negative
    if(maxSubarray < 0)
        return maxSubarray;

    int circularMax = totalSum - minSubarray;

    return (maxSubarray > circularMax) ? maxSubarray : circularMax;
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", maxCircularSum(arr, n));

    return 0;
}
