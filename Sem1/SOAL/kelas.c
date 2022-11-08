#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int i = 0; i < tc; i++)
    {
        char kata1[30], kata2[30];
        scanf("%s",&kata1); getchar();
        scanf("%s",&kata2); getchar();
        int len2 = strlen(kata2);
        if(strcmpi(kata1,kata2) == 0)
        {
            for(int j = 0; j < len2; j++)
            {
                kata2[j] = tolower(kata2[j]);
            }
            printf("Case #%d: %s",i+1,kata2);
        }
        else
        {
            printf("Case #%d: -",i+1);
        }
        printf("\n");
    }
    return 0;
}
