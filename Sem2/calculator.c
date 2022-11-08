#include <stdio.h>

int main()
{
    float a;
    float b;
    scanf("%f",&a); getchar();
    b = (a*a*a) - (1.2*a*a) - 8.19*a + 13.23;
    printf("%f",b);
}