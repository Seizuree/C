#include <stdio.h>

int main()
{
    int percobaan;
    scanf("%d",&percobaan);
    for(int i = 0; i < percobaan; i++)
    {
        double belanja = 0, cbpersen = 0, makscb = 0;
        scanf("%lf %lf %lf",&belanja,&cbpersen,&makscb); getchar();
        double cashback = 0;
        cashback = belanja * (cbpersen / 100);
        printf("Case #%d: ",i+1);
        if(cashback > makscb)
        {
            printf("%.0lf",makscb);
        }
        else
        {
            printf("%.0lf",cashback);
        }
        printf("\n");
    }
    return 0;
}