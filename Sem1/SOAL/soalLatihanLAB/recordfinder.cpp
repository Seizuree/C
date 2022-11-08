#include <stdio.h>
#include <string.h>

struct recordfinder
{
    char alias[100];
    char nama[1000];
    int umur;
    double saldo;
};


int main()
{
    int count;
    scanf("%d",&count); getchar();
    struct recordfinder arr[1000];
    for (int i = 0; i < count; i++)
    {
        scanf("%[^,],%[^,],%d,%lf",&arr[i].alias,&arr[i].nama,&arr[i].umur,&arr[i].saldo); getchar();
    }
    // for (int i = 0; i < count; i++)
    // {
    //     for (int j = 0; j < count-i-1; j++)
    //     {
    //         recordfinder temp = arr[j];
    //         arr[j] = arr[j+1];
    //         arr[j+1] = temp;
    //     }
    // }
    
    int bnykTujuan;
    scanf("%d",&bnykTujuan); getchar();
    char tujuan[100];
    for (int i = 0; i < bnykTujuan; i++)
    {
        scanf("%s",&tujuan); getchar();
        for (int j = 0; j < count; j++)
        {
            if (strcmp(tujuan, arr[i].alias) == 0)
            {
                printf("%s %d %lf\n",arr[i].nama,arr[i].umur,arr[i].saldo);
                break;
            }
            else
            {
                printf("-1\n");
                break;
            }
        }
    }
    return 0;
}