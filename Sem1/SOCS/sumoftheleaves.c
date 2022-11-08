#include <stdio.h>

void leafCount(int first, int total, int *arr, int jumArr)
{
    int sum = 0;
    int temp = arr[first];

    if(first * 2 > jumArr && first * 2 + 1 > jumArr)
    {
        sum = total + temp;
        printf("%d\n",sum);
    }
    else
    {
        if(first * 2 <= jumArr)
        {
            sum = total + temp;
            leafCount(first * 2, sum, arr, jumArr);
        }
        if(first * 2 + 1 <= jumArr)
        {
            sum = total + temp;
            leafCount(first * 2 + 1, sum, arr, jumArr);
        }
    }
}

int main()
{
    int bnyk;
    scanf("%d",&bnyk); getchar();
    for(int i = 1; i <= bnyk; i++)
    {
        int jumArr;
        scanf("%d",&jumArr); getchar();
        int arr[jumArr];
        int jumlah = 0;
        for(int j = 1; j <= jumArr; j++)
        {
            scanf("%d",&arr[j]); getchar();
        }
        printf("Case #%d:\n",i);
        leafCount(1, jumlah, arr, jumArr);
        jumlah = 0;
    }
    return 0;
}
