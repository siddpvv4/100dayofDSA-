#include <stdio.h>

// Recursive function to compute a^b
long long power(int a, int b)
{
    // Base case
    if (b == 0)
        return 1;

    // Recursive case
    return a * power(a, b - 1);
}

int main()
{
    int a, b;

    // Input
    scanf("%d %d", &a, &b);

    // Function call
    long long result = power(a, b);

    // Output
    printf("%lld", result);

    return 0;
}
