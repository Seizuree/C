#include <stdio.h>
#include <string.h>

int main()
{
    for(int i = 0; i < 3; i++)
    {
        int a1;
        char a[255];
        scanf("%d %s",&a1,&a);
        int len = strlen(a) - 1;
        printf("%c%c\n",a[len],a[0]);
    }
    return 0; 
}