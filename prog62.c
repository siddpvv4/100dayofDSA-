#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 30000

typedef struct {
    int *elements;
    int *minStack;
    int topIndex;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->elements = (int*)malloc(sizeof(int) * MAX_SIZE);
    obj->minStack = (int*)malloc(sizeof(int) * MAX_SIZE);
    obj->topIndex = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->topIndex++;
    obj->elements[obj->topIndex] = val;
    
    // If it's the first element, it's the minimum.
    // Otherwise, compare val with the current minimum at (topIndex - 1).
    if (obj->topIndex == 0) {
        obj->minStack[obj->topIndex] = val;
    } else {
        int currentMin = obj->minStack[obj->topIndex - 1];
        obj->minStack[obj->topIndex] = (val < currentMin) ? val : currentMin;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->topIndex >= 0) {
        obj->topIndex--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->elements[obj->topIndex];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->topIndex];
}

void minStackFree(MinStack* obj) {
    free(obj->elements);
    free(obj->minStack);
    free(obj);
}