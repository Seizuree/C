#include <stdio.h>

int main()
{
    char first, second;
    int perkalian;
    scanf("%c", &first); getchar();
    scanf("%c", &second); getchar();
    
    perkalian = first * second;
    printf("%d\n",perkalian);

    return 0;
}