#include <stdio.h>

int main() {
    int count = 0;
    scanf("%d",&count);
    getchar();
    int loginStat[1001];
    for (int i = 0; i < 1000; i++)
    {
        loginStat[i] = 0;
    }
    int sus = 0;
    for (int i = 0; i < count; i++)
    {
        int a = 0;
        scanf("%d",&a); getchar();
        if (a > 0)
        {
            loginStat[a] = 1;
        }
        else
        {
            if (loginStat[(-a)] != 1)
            {
                sus++;
            }
            else loginStat[(-a)] = 0;
        }
    }
    printf("%d\n",sus);
    return 0;
}