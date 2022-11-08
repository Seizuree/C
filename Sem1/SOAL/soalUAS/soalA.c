#include <stdio.h>
#include <string.h>

int convert(char x)
{
    if ('a' <= x && x <= 'z')
    {
        return x - 'a' + 1;
    }
    else if ('A' <= x && x <= 'Z')
    {
        return x - 'A' + 1;
    }
    else
    {
        return 0;
    }
    
}

int main()
{
    char sent[100001];
    int HH, MM;
    scanf("%d:%d>%[^\n]", &HH, &MM, sent); getchar();
    int min = HH*60+MM;
    int len = strlen(sent)
    int i=0, x=0, y=0;
    for(int j=0; j<len; j++)
    {
        if(sent[j]==' ')
        {
            i++;
        }
        if(i == MM/10)
        {
            x += convert(sent[j]);
        }
        if(i == MM%10)
        {
            x += convert(sent[j]);
        }
    }
    x=(x>180) ? x%180:x;
    
    if(min>720)
    {
        x*=-1;
   }
    scanf("%d:%d>%[^\n]", &HH, &MM, sent); getchar();
    min = HH*60+MM; len = strlen(sent); i=0;
    for(int j=0; j<len; j++)
    {
        if(sent[j]==' ')i++;
        if(i == MM/10)
        {
            y += convert(sent[j]);
        }
        if(i == MM%10)
        {
            y += convert(sent[j]);
        }
    }
    y = (y>180) ? y % 180 : y;
    if(min > 720)
    {
        y *= -1;
    }
    printf("Case #1: %d,%d\n", x, y);
}

    
}