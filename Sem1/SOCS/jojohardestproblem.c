#include <stdio.h>

long long int a(long long int x, long long int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int main()
{
    int count;
    scanf("%d",&count); getchar();
    long long int arr1[count+5];
    for (int i = 1; i <= count; i++)
    {
        scanf("%lld",&arr1[i]); getchar();
    }
    long long int tc;
    scanf("%lld",&tc); getchar();

    long long int arr2[count+5];
    for (int i = 1; i <= count; i++)
    {
        arr2[i] = arr2[i - 1] + arr1[i];
    }
    long long int mid = count + 1;
    long long int res = 0;
    long long int first = 0;
    while (mid > 0)
    {
        if (mid > count)
        {
            while (mid > count)
            {
                mid--;
            }
            first = arr1[mid];
        }
        else
        {
            while (first > tc && count > mid)
            {
                long long int temp = arr2[count] - arr2[mid - 1];
                count--;
                first = first - temp;
            }
            if (first <= tc)
            {
                res = a(res,first);
            }
            mid--;
            first = first + (count - mid + 1) * arr1[mid];
        }
        if (first <= tc)
        {
            res = a(res,first);
        }
    }
    printf("%lld\n",res);
    return 0;
}