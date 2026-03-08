#include <stdio.h>

#define MAX 100

int main() {
    int queue[MAX];
    int front = 0, rear = -1;
    int n, m;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
        rear = i;
    }

    scanf("%d", &m);

    front = (front + m) % n;

    for(int i = 0; i < n; i++) {
        printf("%d ", queue[(front + i) % n]);
    }

    return 0;
}