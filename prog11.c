#include <stdio.h>

void moveZeroes(int *nums, int numsSize)
{
    int k = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            nums[k] = nums[i];

            if (k != i)
            {
                nums[i] = 0;
            }

            k++;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    moveZeroes(nums, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
