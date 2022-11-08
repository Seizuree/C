// #include <stdio.h>

// int faktorial (int angka)
// {
//     if(angka == 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return (angka * faktorial(angka - 1));
//     }
// }

// int main()
// {
//     int angka;
//     scanf("%d",&angka); getchar();
//     int hasil = faktorial(angka);
//     printf("%d",hasil);
// }

#include <stdio.h>

int doubleFactorial(int a)
{
    if(a == 0 || a == 1)
    {
        return 1;
    }
    else
    {
        return (a * doubleFactorial(a - 2));
    }
}

int main()
{
    int a;
    scanf("%d",&a);
    int hasil = doubleFactorial(a);
    printf("%d",hasil);
    return 0;
}