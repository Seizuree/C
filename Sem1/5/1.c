#include <stdio.h>

int main(void)
{
    int a;
    scanf("%d",&a); getchar();
    int arr[a];
    for(int i = 0; i < a; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i < a; i++)
    {
        printf("Angka ke %d: %d",i,arr[i]);
        printf("\n");
    }
}