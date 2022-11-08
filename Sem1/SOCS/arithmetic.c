#include <stdio.h>

int main()
{
    int a1,b1,add,sub,multiply,division,modulus;
    scanf("%d %d",&a1,&b1);
    add = a1 + b1;
    sub = a1 - b1;
    multiply = a1 * b1;
    division = a1 / b1;
    modulus = a1 % b1;
    printf("%d\n",add);
    printf("%d\n",sub);
    printf("%d\n",multiply);
    printf("%d\n",division);
    printf("%d\n",modulus);

    return 0;
}