#include <stdio.h>

#define MAX 100

int main() {
    int queue[MAX];
    int front = 0, rear = -1;
    int n, m;

    // Number of elements to enqueue
    scanf("%d", &n);

    // Enqueue elements
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }

    // Number of dequeue operations
    scanf("%d", &m);

    // Perform dequeue
    for(int i = 0; i < m; i++) {
        if(front <= rear || (front > rear)) {
            front = (front + 1) % MAX;
        }
    }

    // Print remaining elements
    int count = n - m;
    for(int i = 0; i < count; i++) {
        printf("%d ", queue[(front + i) % MAX]);
    }

    return 0;
} 