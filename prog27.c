#include <stdio.h>

#define MAX 20

void rotate(int n, int matrix[MAX][MAX])
{
    int i, j, temp;

    // Step 1: Transpose
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for(i = 0; i < n; i++)
    {
        int left = 0;
        int right = n - 1;

        while(left < right)
        {
            temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;

            left++;
            right--;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int matrix[MAX][MAX];

    // Input
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    rotate(n, matrix);

    // Output
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
