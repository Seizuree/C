#include <stdio.h>
#include <string.h>

int main()
{
    int bnyk;
    scanf("%d",&bnyk); getchar();
    char nomor1[1000000];
    for (int i = 0; i < bnyk; i++)
    {
        scanf("%s",&nomor1); getchar();
        int jumlah = 0;
        int panjang = strlen(nomor1);
        for(int j = 0; j < panjang; j++)
        {
          if(j % 2 == 0)
          {
            jumlah = jumlah + (nomor1[j] - '0');
          }
          else if(j % 2 != 0)
          {
            jumlah = jumlah - (nomor1[j] - '0');
          }
        }
        if(jumlah % 11 == 0)
        {
          printf("Case #%d: Yeah\n",i+1);
        }
        else
        {
          printf("Case #%d: Nah\n",i+1);
        }
    }
}
