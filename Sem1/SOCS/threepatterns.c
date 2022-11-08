#include <stdio.h>

int main()
{
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= a;j++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= a; j++)
        {
            if (i % b == 0)
            {
                printf("#");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= a; j++)
        {
            if(j % b == 0)
            {
                printf("#");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}