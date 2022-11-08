#include <stdio.h>

int main()
{
    int tc;
    scanf("%d", &tc);
    getchar();
    for(int i=1; i<=tc; i++)
    {
        int a, b;
        int sum = 0;
        scanf("%d %d", &a, &b);
        getchar();
        int arr[a+5];
        for(int j = 0; j < a; j++)
        {
            scanf("%d", &arr[j]);
            getchar();
        }
        for(int j = 0; j < a; j++)
        {
            for(int k = 0; k < a - 1 - j; k++)
            {
                if(arr[k] > arr[k+1])
                {
                    sum++;
                    int temp = arr[k];
                    arr[k] = arr[k+1];
                    arr[k+1] = temp;
                }
            }
        }
        sum *= b;
        printf("Case #%d: %d\n", i, sum);
    }
    return 0;
} 