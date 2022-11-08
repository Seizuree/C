#include <stdio.h>

int recursive(int x, int y)
{
    if(x == 0 || y == 0)
    {
        return 1;
    }
    return recursive(x-1,y-1) + recursive(x,y-1) + recursive(x-1,y);
}

int main()
{
    int a1, a2;
    scanf("%d %d",&a1,&a2); getchar();
    printf("%d\n",recursive(a1,a2));
    return 0;
}