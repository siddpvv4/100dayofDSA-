#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // input
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    int firstRowZero = 0;
    int firstColZero = 0;

    // check if first row has zero
    for(int j = 0; j < n; j++)
    {
        if(matrix[0][j] == 0)
        {
            firstRowZero = 1;
            break;
        }
    }

    // check if first column has zero
    for(int i = 0; i < m; i++)
    {
        if(matrix[i][0] == 0)
        {
            firstColZero = 1;
            break;
        }
    }

    // mark rows and columns
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // make rows zero
    for(int i = 1; i < m; i++)
    {
        if(matrix[i][0] == 0)
        {
            for(int j = 1; j < n; j++)
                matrix[i][j] = 0;
        }
    }

    // make columns zero
    for(int j = 1; j < n; j++)
    {
        if(matrix[0][j] == 0)
        {
            for(int i = 1; i < m; i++)
                matrix[i][j] = 0;
        }
    }

    // handle first row
    if(firstRowZero)
    {
        for(int j = 0; j < n; j++)
            matrix[0][j] = 0;
    }

    // handle first column
    if(firstColZero)
    {
        for(int i = 0; i < m; i++)
            matrix[i][0] = 0;
    }

    // print matrix
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}
