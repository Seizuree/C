#include <stdio.h>

int main()
{
    int angka1,angka2;
    scanf("%d %d",&angka1,&angka2); getchar();
    int k;
    scanf("%d",&k); getchar();
    int sum = 0;
    for(int i = 0; i < k - 1; i++)
    {
        sum = angka2 + angka1;
        angka1 = angka2;
        angka2 = sum;
    }
    printf("%d\n",angka2);
    return 0;
}