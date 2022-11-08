#include <stdio.h>

int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0;i < testcase;i++)
    {
        int firstnum,secnum;
        scanf("%d %d", &firstnum,&secnum);

        int mil1, mil2, hundredthou1, hundredthou2,tenthou1, tenthou2, thou1, thou2, hundred1, hundred2, doz1, doz2, ones1, ones2;
        mil1 = firstnum - (firstnum%1000000);
        mil2 = secnum - (secnum%1000000);
        hundredthou1 = firstnum - mil1 - (firstnum%100000);
        hundredthou2 = secnum - mil2 - (secnum%100000);
        tenthou1 = firstnum - mil1 - hundredthou1-(firstnum%10000);
        tenthou2 = secnum - mil2 - hundredthou2 - (secnum%10000);
        thou1 = firstnum - mil1 - hundredthou1 - tenthou1 - (firstnum%1000);
        thou2 = secnum - mil2 - hundredthou2 - tenthou2 - (secnum%1000);
        hundred1 = firstnum - mil1 - hundredthou1 - tenthou1 - thou1 - (firstnum%100);
        hundred2 = secnum - mil2 - hundredthou2 - tenthou2 - thou2 - (secnum%100);
        doz1 = firstnum - mil1 - hundredthou1 - tenthou1 - thou1 - hundred1 - (firstnum%10);
        doz2 = secnum - mil2 - hundredthou2 - tenthou2 - thou2 - hundred2 - (secnum%10);
        ones1 = firstnum - mil1 - hundredthou1 - tenthou1 - thou1 - hundred1 - doz1;
        ones2 = secnum - mil2 - hundredthou2 - tenthou2 - thou2 - hundred2 - doz2;
        
        int resmil = mil1 + mil2;
        int reshundredthou = hundredthou1 + hundredthou2;
        int restenthou = tenthou1 + tenthou2;
        int resthou = thou1 + thou2;
        int reshundred = hundred1 + hundred2;
        int resdoz = doz1 + doz2;
        int resones = ones1+ones2;
        
        if(resmil > 10000000)
        {
            resmil %= 10000000;
        }
        if(reshundredthou >= 1000000)
        {
            reshundredthou %= 1000000;
        }
        if(restenthou >= 100000)
        {
            restenthou %= 100000;
        }
        if(resthou >= 10000)
        {
            resthou %= 10000;
        }
        if(reshundred >= 1000)
        {
            reshundred %= 1000;
        }
        if(resdoz >= 100)
        {
            resdoz %= 100;
        }
        if(resones >= 10)
        {
            resones %= 10;
        }
        
        int totalresult = resmil + reshundredthou + restenthou + resthou + reshundred + resdoz + resones;
        printf("Case #%d: %d\n",i+1, totalresult);
    }
    return 0;
}