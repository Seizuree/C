#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int count = 0;
    scanf("%d",&count); getchar();
    long double compare = 0;
    for (int i = 0; i < count; i++)
    {
        char op;
        long double numbers = 0;
        scanf("%c %Lf",&op, &numbers); getchar();
        if (op == '+')
        {
            compare = compare + (int)(pow(2.0, numbers) + 0.5);
        }
        else if (op == '-')
        {
            compare = compare - (int)(pow(2.0, numbers) + 0.5);
        }
        if (compare != 0.0)
        {
            printf("NO\n");
        }
        else printf("YES\n");
    }
    return 0;
}