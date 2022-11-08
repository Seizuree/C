#include <stdio.h>

int main()
{
    long int a1,a2,total=0;
    scanf("%ld %ld", &a1, &a2);
    for(int i = a1; i <= a2; i++)
    {
        total = total + i;
    }
    printf("%ld\n", total);

    return 0;
}
