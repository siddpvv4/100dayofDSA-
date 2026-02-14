#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int matrix[n][n];

    // Input matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int isIdentity = 1;   // assume true

    // Check matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // diagonal elements
            if(i == j)
            {
                if(matrix[i][j] != 1)
                {
                    isIdentity = 0;
                    break;
                }
            }
            // non-diagonal elements
            else
            {
                if(matrix[i][j] != 0)
                {
                    isIdentity = 0;
                    break;
                }
            }
        }

        if(isIdentity == 0)
            break;
    }

    // Output
    if(isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
