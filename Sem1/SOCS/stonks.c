#include <stdio.h>

int main()
{
    long long int percobaan;
    scanf("%lld",&percobaan); getchar();
    long long int arr[percobaan+1];
    long long int sum = 0;
    for(int i = 0; i < percobaan; i++)
    {
        scanf("%lld",&arr[i]); getchar();
        if(arr[i] < 0)
        {
            arr[i] = 0;
        }
    }
    for(int i = 0; i < percobaan; i++)
    {
        
        sum += arr[i];
    }
    printf("%lld\n",sum);
    return 0;
}