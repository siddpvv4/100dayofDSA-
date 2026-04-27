#include <stdio.h>

/**
 * Finds the floor of the square root of n using Binary Search.
 * Uses long long to handle values up to 9e18.
 */
long long integer_sqrt(long long n) {
    // Base cases for 0 and 1
    if (n < 2) {
        return n;
    }

    long long low = 1;
    long long high = n / 2; // The square root of n (for n > 1) is never more than n/2
    long long ans = 1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        /* * Optimization: To avoid overflow (mid * mid), 
         * we use the division logic: mid <= n / mid
         */
        if (mid <= n / mid) {
            ans = mid;      // Store the potential answer
            low = mid + 1;  // Look for a larger integer in the right half
        } else {
            high = mid - 1; // Square is too big, look in the left half
        }
    }

    return ans;
}

int main() {
    long long n;
    printf("Enter a non-negative integer: ");
    if (scanf("%lld", &n) != 1 || n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    printf("The integer square root of %lld is %lld\n", n, integer_sqrt(n));

    return 0;
}
