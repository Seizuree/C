#include <stdio.h>

int main()
{
    long long int angka1;
    scanf("%lld",&angka1); getchar();
    long long int sum = 1;
    for(int i = 0; i < angka1; i++)
    {
        sum = sum * 2;
    }
    printf("%lld\n",sum-1);
    return 0;
}