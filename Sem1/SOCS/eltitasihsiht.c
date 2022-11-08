#include <stdio.h>
#include <string.h>

int main()
{
    int bnyk;
    scanf("%d",&bnyk); getchar();
    for(int i = 0; i < bnyk; i++)
    {
        char kata2[10000];
        scanf("%[^\n]",&kata2); getchar();
        int len = strlen(kata2);
        printf("Case #%d: ",i+1);
        for(int j = len-1; j >= 0; j--)
        {
            printf("%c",kata2[j]);
        }
        printf("\n");
    }
    return 0;
}