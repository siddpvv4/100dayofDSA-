#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void push(int heap[], int *size, int val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, (*size) - 1);
}

void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int main() {
    int k, n;

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter number of initial scores: ");
    scanf("%d", &n);

    int heap[k];
    int size = 0;

    printf("Enter scores:\n");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        if (size < k) {
            push(heap, &size, x);
        } else if (x > heap[0]) {
            heap[0] = x;
            heapifyDown(heap, size, 0);
        }
    }

    int q;
    printf("Enter number of new scores: ");
    scanf("%d", &q);

    printf("Kth largest after each add:\n");

    while (q--) {
        int val;
        scanf("%d", &val);

        if (size < k) {
            push(heap, &size, val);
        } else if (val > heap[0]) {
            heap[0] = val;
            heapifyDown(heap, size, 0);
        }

        printf("%d\n", heap[0]);
    }

    return 0;
}