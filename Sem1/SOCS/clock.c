#include <stdio.h>
#include <string.h>

int main()
{
    int bnyk;
    scanf("%d",&bnyk); getchar();
    for(int i = 1; i <= bnyk; i++)
    {
        int hour, minute;
        char tf[5];
        scanf("%d:%d",&hour,&minute); getchar();
        scanf("%s",&tf); getchar();
        printf("Case #%d: ",i);
        if(strcmp(tf,"am") == 0)
        {
            if(hour == 12)
            {
                hour = 0;
                printf("%.2d:%.2d\n",hour,minute);
            }
            else
            {
                printf("%.2d:%.2d\n",hour,minute);
            }
        }
        else
        {
            if(hour == 12)
            {
                printf("%.2d:%.2d\n",hour,minute);
            }
            else
            {
                hour = hour + 12;
                printf("%.2d:%.2d\n",hour,minute);
            }
        }
    }
    return 0;
}