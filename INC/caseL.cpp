#include <stdio.h>
#include <stdlib.h>

long long int fastPower(long long int base, long long int n){
    long long int res = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res = (res * base) % 998244353;
        }
        base = (base * base) % 998244353;
        n = n / 2;
    }
    return res % 998244353;
}

int main(){
    long long int count = 0;
    scanf("%lld",&count); getchar();
    long long int a[count+5], b[count+5], c[count+5];
}