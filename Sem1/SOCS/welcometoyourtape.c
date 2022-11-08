#include <stdio.h>
#include <string.h>

int main()
{
    int count;
    scanf("%d",&count); getchar();
    for (int i = 0; i < count; i++)
    {
        int banyak, pilihan;
        scanf("%d %d",&banyak,&pilihan); getchar();
        char arr1[banyak+5][105];
        for (int j = 0; j < banyak; j++)
        {
            scanf("%s",&arr1[j]); getchar();
        }
        for (int j = 0; j < banyak; j++)
        {
            for (int k = 0; k < banyak-1-j; k++)
            {
                if (strcmp(arr1[k], arr1[k+1]) > 0)
                {
                    char temp[105];
                    strcpy(temp, arr1[k]);
                    strcpy(arr1[k],arr1[k+1]);
                    strcpy(arr1[k+1], temp);
                }   
            }
        }
        printf("Case #%d: %s\n",i+1,arr1[pilihan-1]);
    }
}