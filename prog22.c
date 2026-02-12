#include <stdio.h>

int main() {
    int m, n;
    
    // Input rows and columns
    scanf("%d %d", &m, &n);

    int a[50][50];

    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Step 1: Check square matrix
    if(m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Step 2: Check symmetry
    int symmetric = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] != a[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if(symmetric == 0)
            break;
    }

    // Output
    if(symmetric == 1)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
