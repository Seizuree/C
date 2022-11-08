#include <stdio.h>

int main()
{
    int a1,b1,c1;
    scanf("%d",&a1); getchar();
    b1 = a1 + a1;
    c1 = b1 - 1;
    printf("%d plus %d is %d\n", a1, a1, b1);
    printf("minus one is %d\n", c1);
    return 0;
}