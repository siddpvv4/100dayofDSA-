#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* answer = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize);
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int index = stack[top--];
            answer[index] = i - index;
        }
        stack[++top] = i;
    }

    free(stack);
    *returnSize = temperaturesSize;
    return answer;
}

int main() {
    int temperatures[] = {73,74,75,71,69,72,76,73};
    int n = sizeof(temperatures) / sizeof(temperatures[0]);
    int returnSize;

    int* result = dailyTemperatures(temperatures, n, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}