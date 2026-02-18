#include <stdio.h>
#include <stdlib.h>

/* Function */
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;

    int* answer = (int*)malloc(numsSize * sizeof(int));

    // LEFT products
    answer[0] = 1;
    for(int i = 1; i < numsSize; i++)
    {
        answer[i] = answer[i-1] * nums[i-1];
    }

    // RIGHT products
    int right = 1;
    for(int i = numsSize - 1; i >= 0; i--)
    {
        answer[i] = answer[i] * right;
        right *= nums[i];
    }

    return answer;
}

/* Driver code */
int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int returnSize;
    int* result = productExceptSelf(nums, n, &returnSize);

    printf("Output array:\n");
    for(int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);

    // free memory
    free(nums);
    free(result);

    return 0;
}
