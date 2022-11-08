#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d",&a);
    for(int i = 0; i < a; i++)
    {
        scanf("%d",&b);
        for(int j = 0; j < b;j++)
        {
            for(int k = 0; k < b; k++)
            {
                if(j == 0 || k == 0 || j == b-1 || k == b-1 || k == b-j-1 || j == k)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}