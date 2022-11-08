#include <stdio.h>

int main()
{
    int a,i,j;
    scanf("%d",&a);
    for(i = 0; i < a; i++)
    {
        long long int b,c;
        scanf("%lld",&b);
        long long int jumlah = 0;
        for(j = 0; j < b; j++)
        {
            scanf("%lld",&c);
            jumlah += c;
        }
        printf("Case #%d: %lld\n",i+1,jumlah);
    }
    return 0;
}