#include <stdio.h>

int main()
{
    int a;
    scanf("%d",&a);
    int arr[a];
    for(int i=0; i < a;i++)
    {
        scanf("%d",&arr[i]);
    }
    int b;
    int chg1,chg2;
    scanf("%d",&b);
    for(int i=0; i < b;i++)
    {
        scanf("%d %d",&chg1,&chg2);
        arr[chg1-1]=chg2;
        printf("Case #%d: ",(i+1));
        for(int j = 0; j < a;j++)
        {
            if(j == a-1)
            {
                printf("%d", arr[j]);
            }
            else
            {
                printf("%d ",arr[j]);
            }
        }
        printf("\n");
    }
    // trailing space
    
    return 0;
}