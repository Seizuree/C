#include <stdio.h>

int main()
{
    int a1;
    scanf("%d", &a1);
    for(int i = 0; i < a1; i++)
    {
        int b1,b2;
        scanf("%d %d",&b1, &b2); getchar();
        printf("%d\n", ((b1/b2) << b2));
    }

    return 0;
}