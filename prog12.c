//RECURSION FIBONACCI
#include <stdio.h>

// recursive function
int fib(int n)
{
    // base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // recursive call
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    // input
    scanf("%d", &n);

    // output
    printf("%d", fib(n));

    return 0;
}
