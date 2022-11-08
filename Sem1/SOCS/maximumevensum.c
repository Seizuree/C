#include <stdio.h>

int main()
{
    long long int panjang;
    scanf("%lld",&panjang);
    long long int arr[panjang+5];
    long long int sum = 0;
    long long int minimum = 100000;
    for(int i = 0; i < panjang; i++)
    {
        scanf("%lld",&arr[i]);
        sum += arr[i];
    }
    if(sum %2 != 0)
    {
        for(int j = 0; j < panjang; j++)
        {
            if(minimum > arr[j] && arr[j] %2 != 0)
            {
                minimum = arr[j];
            }
        }
        sum = sum - minimum;
    }
    printf("%lld\n",sum);
    return 0;
}