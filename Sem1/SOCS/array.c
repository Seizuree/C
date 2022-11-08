#include<stdio.h>

int main()
{
    int a;
    scanf("%d",&a);
    int arr1[a+1];
    int arr2[a+1];
    int i;
    for(i=0; i < a;i++)
    {
        scanf("%d",&arr1[i]);
    }
    for(i=0; i < a;i++)
    {
        scanf("%d",&arr2[arr1[i]]);
    }
    for(i=0; i < a;i++)
    {
        if(i == a-1)
        {
            printf("%d\n",arr2[i]);
        }
        else{
            printf("%d ",arr2[i]);
        }
    }
    return 0;
}