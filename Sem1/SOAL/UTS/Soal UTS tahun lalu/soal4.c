#include <stdio.h>

int main()
{
    int T;
    int merah,hitam, c;
    int sumR, sumB;
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &c, &merah, &hitam);
            int counter = 0;
            while(merah + hitam <= c)
            {
                counter++;
                merah = sumR;
                hitam = sumB;
                
                if(counter%4 == 0)
                {
                    sumR = sumR - sumR/3;
                }
                else
                {
                    sumR = sumR * 2;
                }
                if(counter%3 == 0)
                {
                    sumB = sumB - sumB * 4/5;
                }
                else
                {
                    sumB = sumB * 3;
                }
            }
            if(merah == hitam)
            {
                printf("Case #%d: %d None",i+1, counter-1);
            }
            else if(merah > hitam)
            {
                printf("Case #%d: %d Red",i+1, counter-1);
            }
            else if(hitam > merah)
            {
                printf("Case #%d: %d Black",i+1, counter-1);
            }
        if(merah > hitam)
        {
            printf("%d\n", merah - hitam);
        }
        else
        {
            printf("%d\n", hitam - merah);
        }
    }
    return 0;
}