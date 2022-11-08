#include <stdio.h>
#include <math.h>

int main()
{
    int testcase;
    int factor = 0;
    scanf("%d",&testcase);
    for(int i = 0; i < testcase; i++)
    {
        long long int angka;    
        scanf("%lld",&angka); getchar();
        for(int j = 1; j <= sqrt(angka); j++)
        {
            if(angka % j == 0)
            {
                if(angka / j == j)
                {
                    factor++;
                }
                else
                {
                    factor += 2;
                }
            }
        }
        printf("Case #%d: %d\n",i+1,factor);
        factor = 0;
    }
    return 0;
}