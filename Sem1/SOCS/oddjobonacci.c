#include <stdio.h>

int oddJobonacci(int angka1)
{
    if(angka1 % 2 != 0)
    {
        return 1;
    }
    if(angka1 == 0)
    {
        return angka1;
    }
    else if(angka1 == 1)
    {
        return angka1;
    }
    else
    {
        return (oddJobonacci(angka1-1) + oddJobonacci(angka1-2));
    }
}

int main()
{
    int angka1;
    scanf("%d",&angka1); getchar();
    printf("%d\n",oddJobonacci(angka1));
    return 0;
}