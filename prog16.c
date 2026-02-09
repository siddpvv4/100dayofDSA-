//Mirror the Code Name
#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    int i, length;

    // Input
    scanf("%s", str);

    // Find length of string
    length = strlen(str);

    // Reverse printing
    for(i = length - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    return 0;
}
