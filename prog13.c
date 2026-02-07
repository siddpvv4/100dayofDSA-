#include <stdio.h>

// Recursive Fibonacci function
int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}

int main()
{
    int n, result;

    printf("Enter n: ");
    scanf("%d", &n);

    result = fib(n);

    printf("Fibonacci number at position %d is %d\n", n, result);

    return 0;
}
