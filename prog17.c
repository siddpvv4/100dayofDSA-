#include <stdio.h>

void reverseString(char s[], int n)
{
    int left = 0;
    int right = n - 1;
    char temp;

    while(left < right)
    {
        // swap characters
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main()
{
    char s[] = {'h','e','l','l','o'};
    int n = sizeof(s)/sizeof(s[0]);

    reverseString(s, n);

    // print reversed array
    for(int i = 0; i < n; i++)
        printf("%c ", s[i]);

    return 0;
}
