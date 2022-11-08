#include <stdio.h>

int main()
{
    long long int a,j,i;
    scanf("%lld",&a);
    for(i = 0; i < a; i++)
    {
        long long int b = 0;
        scanf("%lld",&b);
        long long int arr1[b];
        long long int arr2[b];
        long long int res[b];
        for(j = 0; j < b; j++)
        {
            scanf("%lld",&arr1[j]);
        }
        for(j = 0; j < b; j++)
        {
            scanf("%lld",&arr2[j]);
        }
        for(j = 0; j < b; j++)
        {
            res[j]=arr1[j]-arr2[j];
        }
        printf("Case #%lld: ",(i+1));
        for(j = 0; j < b; j++)
        { 
            printf("%lld",res[j]);
            if (j < b-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}