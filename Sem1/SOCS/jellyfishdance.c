#include <stdio.h>

int main()
{
    int w;
    scanf("%d", &w);
    int arr[w];
    for(int i = 0; i < w; i++)
    {
        scanf("%d", &arr[i]); getchar();
    }
    int e;
    scanf("%d", &e);
    int a, b;
    for(int i = 1; i <= e; i++)
    {
        scanf("%d %d", &a, &b); getchar();
        long long int sum = 0;
        for(int j = a; j <= b; j++)
        {
            sum += arr[j-1];
        }
        printf("Case #%d: %d\n", i, sum);
    }
    return 0;
}