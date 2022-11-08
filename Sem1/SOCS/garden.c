#include <stdio.h>

int main()
{
    long int x,y;
    long int i,j,k;
    scanf("%ld %ld",&x,&y);
    long int a[x+1][y+1];
    for(i = 0; i < x; i++)
    {
        for(j = 0; j < y;j++)
        {
            scanf("%ld",&a[i][j]);
        }
    }
    long int x1,xi1,xi2,xi3;
    scanf("%ld",&x1);
    for(k = 0; k < x1; k++)
    {
        scanf("%ld %ld %ld",&xi1,&xi2,&xi3);
        a[xi1-1][xi2-1]=xi3;
    }
    for(i = 0; i < x;i++)
    {
        for(j = 0; j < y;j++)
        {
            if(j == y-1)
            {
                printf("%ld",a[i][j]);
            }
            else
            {
                printf("%ld ",a[i][j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}