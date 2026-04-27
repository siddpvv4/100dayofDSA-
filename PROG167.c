#include <stdio.h>

int mySqrt(int x) {
    if (x < 2) return x;

    int left = 1, right = x / 2;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Use division to avoid overflow: mid*mid might overflow
        if (mid <= x / mid) {
            ans = mid;        // mid is a valid answer
            left = mid + 1;   // try for a bigger value
        } else {
            right = mid - 1;  // reduce search space
        }
    }

    return ans;
}

int main() {
    int x;
    scanf("%d", &x);

    printf("%d\n", mySqrt(x));
    return 0;
}
