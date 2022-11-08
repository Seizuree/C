#include <stdio.h>

int main()
{
    long long int t;
	scanf("%lld", &t);
	getchar();
	for(int i = 1; i <= t; ++i)
    {
        long long int bnyk;
        scanf("%lld", &bnyk); getchar();
        long long int arr[bnyk];
        long long int jum1 = 0;
        for(int j = 0; j < bnyk; j++)
        {
            scanf("%lld",&arr[j]); getchar();
            jum1 = jum1 + arr[j];
        }
        long long int jumlah = 0;
        printf("Case #%d: %lld\n",i,jum1);
        for(int j = 0; j < bnyk; j++)
        {
            if(arr[j] > jum1)
            {
                jumlah++;
            }
        }
        printf("%lld\n", jumlah);
    }
    return 0;
}