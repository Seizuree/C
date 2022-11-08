#include <stdio.h>

int main()
{
    int angka1, angka2, angka3, angka4, angka5, angka6, hasil1, hasil2, hasil3;
    char uu, o;

    scanf("%d %c %d %c", &angka1, &uu, &angka2, &o); getchar();
    scanf("%d %c %d %c", &angka3, &uu, &angka4, &o); getchar();
    scanf("%d %c %d %c", &angka5, &uu, &angka6, &o); getchar();

    if(uu == '+')
    {
        hasil1 = angka1 + angka2;
        hasil2 = angka3 + angka4;
        hasil3 = angka5 + angka6;
    }
    else;
    printf("%d\n",hasil1);
    printf("%d\n",hasil2);
    printf("%d\n",hasil3);

    return 0;
}