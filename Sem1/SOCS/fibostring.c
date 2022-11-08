#include <stdio.h>

void fiboStr(int len, char a, char b)
{
    if(len == 0)
    {
        printf("%c",a);
    }
    else if (len == 1)
    {
        printf("%c",b);
    }
    else
    {
        fiboStr(len-1,a,b);
        fiboStr(len-2,a,b);
    }
}

int main()
{
    int bnyk;
    scanf("%d",&bnyk); getchar();
    for(int i = 0; i < bnyk; i++)
    {
        int len;
        char a, b;
        scanf("%d %c %c",&len, &a,&b); getchar();
        printf("Case #%d: ",i+1);
        fiboStr(len,a,b);
        printf("\n");
    }
    return 0;
}