#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int *deque = (int*)malloc(sizeof(int) * numsSize);

    int front = 0, rear = 0;
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {

        // Remove elements out of this window
        if (front < rear && deque[front] <= i - k)
            front++;

        // Remove smaller elements from rear
        while (front < rear && nums[deque[rear - 1]] < nums[i])
            rear--;

        // Add current index
        deque[rear++] = i;

        // Store result once window size reached
        if (i >= k - 1)
            result[(*returnSize)++] = nums[deque[front]];
    }

    return result;
}