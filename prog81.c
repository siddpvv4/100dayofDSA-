#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int value) {
    queue[++rear] = value;
}

int dequeue() {
    return queue[front++];
}

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Move queue → stack
    while(front <= rear) {
        push(dequeue());
    }

    // Move stack → queue
    front = 0;
    rear = -1;
    while(top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}