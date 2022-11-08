#include <stdio.h>

int main()
{
    int testcase;
    int testresult;
    scanf("%d",&testcase);
    for(int i = 0; i < testcase; i++)
    {
        scanf("%d",&testresult);
        long long int arr1[testresult+1];
        long long int arr2[testresult+1];
        for(int j = 1; j <= testresult; j++)
        {
            scanf("%lld",&arr1[j]);
        }
        int salah = 0;
        for(int k = 1; k <= testresult; k++)
        {
            scanf("%lld",&arr2[k]);
            if(arr1[k] < arr2[k])
            {
                salah+= 1;
            }
        }
        printf("Case #%d: %d\n",i+1,salah);
    }
    return 0;
}