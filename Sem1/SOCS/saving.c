// #include <stdio.h>

// int main()
// {
//     int first;
//     double bunga;
    
//     scanf("%d %lf", &first, &bunga); getchar();
//     bunga = bunga / 100;
//     double second, third, fourth;
    
//     second = (first * bunga) + first;
//     third = (second * bunga) + second;
//     fourth = (third * bunga) + third;

//     printf("%.2lf\n",fourth);
//     return 0;

// }
#include <stdio.h>

int main()
{
    int i;
    char c[255];
    scanf("%d",&i); getchar();
    scanf("%[^\n]", &c); getchar();
    while(i > 5)
    {
        printf("%s\n",c);
        ++i;
    }
    return 0;
}