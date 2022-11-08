#include <stdio.h>

int jumlah = 0;

int tillOne(long long int angka1)
{
    if(angka1 == 1)
    {
        jumlah++;
        return angka1;
    }
    else if(angka1 % 2 == 0)
    {
        return tillOne(angka1/2);
    }
    else if(angka1 % 2 != 0)
    {
        return (tillOne(angka1-1) + tillOne(angka1+1));
    }
}

int main()
{
    int bnyk;
    scanf("%d",&bnyk); getchar();
    for(int i = 0; i < bnyk; i++)
    {
        long long int angka1;
        scanf("%lld",&angka1); getchar();
        tillOne(angka1);
        printf("Case #%d: %d",i+1,jumlah);
        printf("\n");
        jumlah = 0;
    }
    return 0;
}