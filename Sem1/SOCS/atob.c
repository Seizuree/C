#include <stdio.h>

int main()
{
    int bnyk; 
    scanf("%d",&bnyk); getchar();
    for(int i = 0; i < bnyk; i++)
    {
        long long int angka1, angka2;
        scanf("%lld %lld",&angka1,&angka2); getchar();
        for(int j = 0; angka1 != angka2; j++)
        {
            if(angka1 % 2 == 0)
            {
                angka1 = angka1 / 2;
            }
            else if(angka1 % 2 == 1)
            {
                angka1 = angka1 * 3 + 1;
            }
            if(j == 100000)
            {
                break;
            }
        }
        if(angka1 == angka2)
        {
            printf("Case #%d: YES\n",i+1);
        }
        else
        {
            printf("Case #%d: NO\n",i+1);
        }
    }
    return 0;
}