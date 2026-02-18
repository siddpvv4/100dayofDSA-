#include <stdio.h>

int maxSubArray(int* nums, int numsSize) 
{
    int current_sum = 0;
    int max_sum = nums[0];   // important: handles all negative arrays

    for(int i = 0; i < numsSize; i++)
    {
        current_sum += nums[i];

        // update maximum
        if(current_sum > max_sum)
            max_sum = current_sum;

        // reset if negative
        if(current_sum < 0)
            current_sum = 0;
    }

    return max_sum;
}
