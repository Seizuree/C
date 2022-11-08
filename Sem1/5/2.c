#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[255];
    char b;
    scanf("%s %c",&a,&b);
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        if (a[i] == b)
        {
            a[i] = ' ';
        }
        if (a[i] == ' ')
        {
            for (int j = i; j < len; j++)
            {
                a[j] = a[j+1];
            }
            len--;
        }
    }
    printf("%s\n",a);
    return 0;
}