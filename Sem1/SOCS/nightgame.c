#include <stdio.h>

int main()
{
    int banyak;
    scanf("%d",&banyak);
    for(int k = 0; k < banyak; k++)
    {
        int x;
        scanf("%d",&x);
        int arr[x+1];
        int i;
        int jum;
        for(i = 0; i < x; i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("Case #%d: ",k+1);
        for(i = 0; i < x; i++)
        {
            if(i == x-1)
            {
                printf("%d",arr[x-i-1]);
            }
            else
            {
                printf("%d ",arr[x-i-1]);
            }
        }
        printf("\n");
    }
    return 0;
}