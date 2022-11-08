#include <stdio.h>

int main(void)
{
    int a,i,j;
    scanf("%d",&a);
    for(i = 0; i < a; i++)
    {
        int a1,a2;
        scanf("%d %d",&a1,&a2);
        printf("Case #%d: ",i+1);
        if(a1 > a2)
        {
            printf("Go-Jo");
        }
        else
        {
            printf("Bi-Pay");
        }
        printf("\n");
    }
}