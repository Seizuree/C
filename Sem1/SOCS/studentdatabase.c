#include <stdio.h>

struct studentdatabase
{
    char id[25];
    char nama[105];
    int umur;
};


int main()
{
    int bnyk;
    scanf("%d",&bnyk); getchar();
    struct studentdatabase arr[bnyk+5];
    for (int i = 0; i < bnyk; i++)
    {
        scanf("%s",arr[i].id); getchar();
        scanf("%[^\n]",arr[i].nama);
        scanf("%d",&arr[i].umur); getchar();
    }
    int banyakPrint;
    scanf("%d",&banyakPrint); getchar();
    for (int i = 0; i < banyakPrint; i++)
    {
        int nomor;
        scanf("%d",&nomor); getchar();
        printf("Query #%d:\n",i+1);
        printf("ID: %s\n",arr[nomor-1].id);
        printf("Name: %s\n",arr[nomor-1].nama);
        printf("Age: %d\n",arr[nomor-1].umur);
    }
    return 0;
}