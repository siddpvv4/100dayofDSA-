#include <stdio.h>
#include <stdbool.h>

// function to check power of two
bool isPowerOfTwo(int n)
{
    // 0 and negative numbers are not powers of 2
    if (n <= 0)
        return false;

    // bit manipulation trick
    if ((n & (n - 1)) == 0)
        return true;
    else
        return false;
}

int main()
{
    int n;

    // input
    scanf("%d", &n);

    // function call
    if (isPowerOfTwo(n))
        printf("true");
    else
        printf("false");

    return 0;
}
