#include <stdio.h>

int main()
{
    int a;
    scanf("%d",&a); getchar();
    int arr[a];
    int nilai1,nilai2,nilai3;
    scanf("%d %d %d",&nilai1,&nilai2,&nilai3);
    int jumlah = 0;
    for(int i = 0; i < a; i++)
    {
        scanf("%d",&arr[i]); 
        getchar();
        jumlah += arr[i];
    }
    int jum = nilai1+nilai2+nilai3;
    jumlah = jumlah + jum;
    jumlah /= a+3;
    if(nilai1 >= jumlah)
    {
        printf("Jojo lolos\n");
    }
    else
    {
        printf("Jojo tidak lolos\n");
    }
    if(nilai2 >= jumlah)
    {
        printf("Lili lolos\n");
    }
    else
    {
        printf("Lili tidak lolos\n");
    }
    if(nilai3 >= jumlah)
    {
        printf("Bibi lolos\n");
    }
    else
    {
        printf("Bibi tidak lolos\n");
    }
    return 0;
}