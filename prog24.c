#include <stdio.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[r][c];

    // input matrix
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int right = c - 1;

    while(top <= bottom && left <= right)
    {
        // 1. Left → Right (top row)
        for(int i = left; i <= right; i++)
        {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // 2. Top → Bottom (right column)
        for(int i = top; i <= bottom; i++)
        {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // 3. Right → Left (bottom row)
        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
            {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // 4. Bottom → Top (left column)
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
            {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    return 0;
}
