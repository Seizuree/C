#include <stdio.h>
#include <string.h>

int main()
{
    int count, x;
    scanf("%d %d",&count, &x); getchar();
    char str[205][205];
    for (int i = 0; i < count; i++)
    {
        scanf("%s",str[i]); getchar();
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < x-1; j++)
        {
            for (int k = 0; k < x-1; k++)
            {
                if (str[i][k] > str[i][k+1])
                {
                    char temp = str[i][k];
                    str[i][k] = str[i][k+1];
                    str[i][k+1] = temp;
                }
            }
        }
    }
    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count-1; j++)
        {
            if (strcmp(str[j], str[j+1]) < 0)
            {
                char temp[205];
                strcpy(temp, str[j]);
                strcpy(str[j], str[j+1]);
                strcpy(str[j+1], temp);
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s\n",str[i]);
    }
    return 0;
}