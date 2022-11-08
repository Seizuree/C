#include <stdio.h>

int sum = 0;
int fibonacci(int number)
{
    if(number == 1)
    {
        sum++;
        return number;
    }
    else if(number == 0)
    {
        sum++;
        return number;
    }
    else
    {
        sum++;
        return (fibonacci(number - 1) + fibonacci(number - 2));
    }
}

int main()
{
    int bnyk;
    int number = 0;
    scanf("%d",&bnyk); getchar();
    for(int i = 1; i <= bnyk;i++)
    {
        scanf("%d",&number); getchar();
        fibonacci(number);
        printf("Case #%d: %d\n",i,sum);
        sum = 0;
    }
    return 0;
}