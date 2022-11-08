#include <stdio.h>

int main()
{
    long long int a,b,c,d,a1,b1;
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    a1 = a * b;
    b1 = c - d;
    if(a1 == b1)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return 0;
}