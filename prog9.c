#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;        // last valid index of nums1
    int j = n - 1;        // last index of nums2
    int k = m + n - 1;    // last index of merged array

    // Merge from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements of nums2 (if any)
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int m, n;

    // Input sizes
    printf("Enter number of elements in nums1 (m): ");
    scanf("%d", &m);

    printf("Enter number of elements in nums2 (n): ");
    scanf("%d", &n);

    int nums1[m + n];
    int nums2[n];

    // Input nums1 elements
