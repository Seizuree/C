#include <stdio.h>
#include <math.h>

int main()
{
    int count;
    scanf("%d",&count); getchar();
    if (count == 1)
    {
        printf("*\n");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            int counter = 0;
            for (int j = 1; j <= pow(2,count)-1; j++)
            {
                if (counter < pow(2,count-i)-1)
                {
                    if (i == 0)
                    {
                        printf("*");
                        counter++;
                    }
                    else
                    {
                        if (j % (int)(pow(2,i)) == 0)
                        {
                            printf("*");
                            counter++;
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}

