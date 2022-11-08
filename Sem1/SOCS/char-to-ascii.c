#include <stdio.h>
#include <string.h>

int main()
{
    int total;
    scanf("%d",&total);
    char s[1000];
    for(int i = 0; i < total; i++)
    {
        scanf("%s",&s);
        int len = strlen(s);
        printf("Case %d: ", i+1);
        for(int j = 0; j < len; j++)
        {
            if(j == len - 1)
            {
                printf("%d",s[j]);  
            }
            else
            {
                printf("%d-",s[j]);
            }
        }
        printf("\n");
    }
    return 0;
}