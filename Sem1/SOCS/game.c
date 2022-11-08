#include <stdio.h>

int main()
{
    int kata,ukur;
    scanf("%d %d",&kata,&ukur);
    char ukurankata[10001];
    scanf("%s",&ukurankata);
    int chg[ukur];
    for(int i = 0; i < ukur; i++)
    {
        scanf("%d",&chg[i]);
        if(ukurankata[chg[i]] >= 'a' && ukurankata[chg[i]] <= 'z')
        {
            ukurankata[chg[i]] -= 32;
        }
        else if(ukurankata[chg[i]] >= 'A' && ukurankata[chg[i]] <= 'Z')
        {
            ukurankata[chg[i]] += 32;
        }
    }
    printf("%s\n",ukurankata);
    return 0;
}