#include <stdio.h>

int main()
{
    int testcase;
    scanf("%d",&testcase);
    getchar();
    for(int i = 0; i < testcase; i++)
    {
        int t;
        int count = 0;
        int a = 0;
        int max = 0;
        long long int jum = 0;
        scanf("%d",&t);
        long long int arr[t+1];
        for(int j = 0; j < t; j++)
        {
            scanf("%lld",&arr[j]);
            getchar();
        }
        for(int j = 0; j < t;j++)
        {
            for(int k = 0; k < t - 1 -j; k++)
            {
                if(arr[k] > arr[k+1])
                {
                    long long int temp = arr[k];
                    arr[k] = arr[k+1];
                    arr[k+1] = temp;
                }
            }
        }
        for(int j = 0; j < t;j++)
        {
            for(int k = j; k < t; k++)
            {
                if(arr[j] == arr[k])
                {
                    count++;
                    a++;
                }
                else if(arr[j] != arr[k])
                {
                    a--;
                    break;
                }
            }
            if(count > max)
            {
                max = count;
                jum = arr[j];
            }
            j = j+a;
            count = 0;
        }
        printf("Case #%d: %d\n",i+1, max);
        printf("%lld\n",jum);
    }
    return 0;
}