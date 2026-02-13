#include <stdio.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[10][10];   // constraints ≤ 10 so safe

    // input
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

    // spiral traversal
    while(top <= bottom && left <= right)
    {
        // 1. top row
        for(int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        // 2. right column
        for(int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        // 3. bottom row
        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        // 4. left column
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }

    return 0;
}
