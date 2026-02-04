#include <stdio.h>

// Function to remove all occurrences of val
int removeElement(int nums[], int n, int val) {
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    int n, val;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    // Input array elements
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Input value to remove
    printf("Enter value to remove: ");
    scanf("%d", &val);

    // Call function
    int k = removeElement(nums, n, val);

    // Output result
    printf("\nNumber of elements after removal = %d\n", k);

    printf("Updated array: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");

    return 0;
}
