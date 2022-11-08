#include <stdio.h>

int main()
{
    int testcase;
    scanf("%d",&testcase);
    for(int i = 0; i < testcase; i++)
    {
        int inputs;
        scanf("%d",&inputs);
        printf("Case #%d:\n",i+1);
        for(int j = 1; j <= inputs; j++)
        {
            if((j % 3 == 0 || j % 5 == 0) && j % 15 != 0)
            {
                printf("%d Jojo\n",j);
            }
            else
            {
                printf("%d Lili\n",j);
            }
        }
    }
    return 0;
}