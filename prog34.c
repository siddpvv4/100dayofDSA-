#include <stdio.h>

// function to reverse part of array
void reverse(int arr[], int start, int end)
{
    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int n;

    // input n
    scanf("%d", &n);

    int arr[n];

    // input elements
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // input k
    int k;
    scanf("%d", &k);

    // important step
    k = k % n;   // handles k > n

    // Step 1: reverse whole array
    reverse(arr, 0, n-1);

    // Step 2: reverse first k elements
    reverse(arr, 0, k-1);

    // Step 3: reverse remaining
    reverse(arr, k, n-1);

    // print rotated array
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
