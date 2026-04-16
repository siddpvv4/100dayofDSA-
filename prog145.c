#include <stdio.h>
#include <stdlib.h>

// Function to find maximum length of subarray with sum 0
int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;

    // Create a hash map (using array for simplicity)
    // Range assumption for sum (-100000 to 100000)
    int hash[200001];
    
    // Initialize all values to -2 (means not visited)
    for(int i = 0; i < 200001; i++)
        hash[i] = -2;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        // If sum is 0, update max_len
        if(sum == 0)
            max_len = i + 1;

        // Map sum to index (shift by 100000 to handle negatives)
        int index = sum + 100000;

        // If seen before
        if(hash[index] != -2) {
            int len = i - hash[index];
            if(len > max_len)
                max_len = len;
        } else {
            // Store first occurrence
            hash[index] = i;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));
    return 0;
}
