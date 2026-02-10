#include <stdio.h>

int main()
{
    int n, m;

    // input sizes
    scanf("%d", &n);
    int nums1[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &nums1[i]);

    scanf("%d", &m);
    int nums2[m];

    for(int i = 0; i < m; i++)
        scanf("%d", &nums2[i]);

    // frequency array
    int freq[1001] = {0};

    // count elements of nums1
    for(int i = 0; i < n; i++)
        freq[nums1[i]]++;

    // intersection
    int result[1000];
    int k = 0;

    for(int i = 0; i < m; i++)
    {
        if(freq[nums2[i]] > 0)
        {
            result[k++] = nums2[i];
            freq[nums2[i]]--;
        }
    }

    // print result
    for(int i = 0; i < k; i++)
        printf("%d ", result[i]);

    return 0;
}
