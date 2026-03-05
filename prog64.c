#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    char tokens[100][20];
    int stack[100];
    int top = -1;

    printf("Enter number of tokens: ");
    scanf("%d", &n);

    printf("Enter tokens:\n");
    for(int i = 0; i < n; i++)
        scanf("%s", tokens[i]);

    for(int i = 0; i < n; i++)
    {
        if(strcmp(tokens[i], "+") == 0 ||
           strcmp(tokens[i], "-") == 0 ||
           strcmp(tokens[i], "*") == 0 ||
           strcmp(tokens[i], "/") == 0)
        {
            int b = stack[top--];
            int a = stack[top--];
            int result;

            if(strcmp(tokens[i], "+") == 0)
                result = a + b;
            else if(strcmp(tokens[i], "-") == 0)
                result = a - b;
            else if(strcmp(tokens[i], "*") == 0)
                result = a * b;
            else
                result = a / b;

            stack[++top] = result;
        }
        else
        {
            stack[++top] = atoi(tokens[i]);
        }
    }

    printf("Result = %d\n", stack[top]);

    return 0;
}