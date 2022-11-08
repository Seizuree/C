#include <stdio.h>

int main()
{
    int count;
    scanf("%d",&count); getchar();
    int sizeArr;
    for (int i = 1; i <= count; i++)
    {
        scanf("%d",&sizeArr); getchar();
        int arr[sizeArr+5];
        for (int j = 0; j < sizeArr; j++)
        {
            scanf("%d",&arr[j]); getchar();
        }
        int temp = 1000000;
        for (int j = 0; j < sizeArr; j++)
        {
            for (int k = j+1; k < sizeArr; k++)
            {
                if (arr[j] > arr[k])
                {
                    if (arr[j] - arr[k] < temp)
                    {
                        temp = arr[j] - arr[k];
                    }
                }
                else if (arr[k] > arr[j])
                {
                    if (arr[k] - arr[j] < temp)
                    {
                        temp = arr[k] - arr[j];
                    }
                }
                
            }
        }
        printf("Case #%d: %d\n",i,temp);
    }
    return 0;
}