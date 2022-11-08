#include <stdio.h>

int main()
{
    int angka1, angka2, hasil;
    scanf("%d %d",&angka1, &angka2);
    hasil = angka1 % angka2;
    printf("%d\n", hasil);

    return 0;
}