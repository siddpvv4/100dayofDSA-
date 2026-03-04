#include <stdio.h>

#define MAX 1000

int main() {
    int stack[MAX];
    int top = -1;
    int n, m, i;

    // Read number of elements to push
    scanf("%d", &n);

    // Push elements
    for(i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        stack[++top] = value;
    }

    // Read number of pops
    scanf("%d", &m);

    // Pop m elements
    for(i = 0; i < m; i++) {
        if(top >= 0) {
            top--;
        }
    }

    // Print remaining elements from top to bottom
    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}