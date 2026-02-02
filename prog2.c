#include <stdio.h>

int main() {
    int n, pos, x;

    // Input size of array
    scanf("%d", &n);

    int arr[100];  // assuming max size

    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position (1-based)
    scanf("%d", &pos);

    // Input element to insert
    scanf("%d", &x);

    // Shift elements to the right (start from last element)
    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element at correct index
    arr[pos - 1] = x;

    // Print updated array (size becomes n+1)
    for(int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
