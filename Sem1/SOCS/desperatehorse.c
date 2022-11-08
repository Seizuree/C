#include <stdio.h>

int jum = 0;
int sum = 0;
char catur[255][255];

void chess(int x, int y, int tujuanX, int tujuanY, int sum)
{
    if(sum > 6)
    {
        return;
    }
    else if(x < 0 || y > 8 || x > 8 || y < 0)
    {
        return;
    }
    
    if(x == tujuanX && y == tujuanY)
    {
        if(jum == 0 || sum < jum)
        {
            jum = sum;
        }
        return;
    }

    chess(x+1, y+2, tujuanX, tujuanY, sum+1);
    chess(x-1, y+2, tujuanX, tujuanY, sum+1);
    chess(x+1, y-2, tujuanX, tujuanY, sum+1);
    chess(x-1, y-2, tujuanX, tujuanY, sum+1);
    chess(x-2, y+1, tujuanX, tujuanY, sum+1);
    chess(x+2, y+1, tujuanX, tujuanY, sum+1);
    chess(x-2, y-1, tujuanX, tujuanY, sum+1);
    chess(x+2, y-1, tujuanX, tujuanY, sum+1);
}

int main()
{
    int bnyk;
    scanf("%d",&bnyk); getchar();
    for(int i = 1; i <= bnyk; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            for(int k = 0; k < 8; k++)
            {
                catur[j][k] = '\0';
            }
        }
        
        char a, tujuanA;
        int x, y, tujuanX, tujuanY;
        scanf("%c%d",&a,&y); getchar();
        scanf("%c%d",&tujuanA,&tujuanY); getchar();
        if(a == 'A')
        {
            x = 1;
        }
        else if(a == 'B')
        {
            x = 2;
        }
        else if(a == 'C')
        {
            x = 3;
        }
        else if(a == 'D')
        {
            x = 4;
        }
        else if(a == 'E')
        {
            x = 5;
        }
        else if(a == 'F')
        {
            x = 6;
        }
        else if(a == 'G')
        {
            x = 7;
        }
        else if(a == 'H')
        {
            x = 8;
        }
        if(tujuanA == 'A')
        {
            tujuanX = 1;
        }
        else if(tujuanA == 'B')
        {
            tujuanX = 2;
        }
        else if(tujuanA == 'C')
        {
            tujuanX = 3;
        }
        else if(tujuanA == 'D')
        {
            tujuanX = 4;
        }
        else if(tujuanA == 'E')
        {
            tujuanX = 5;
        }
        else if(tujuanA == 'F')
        {
            tujuanX = 6;
        }
        else if(tujuanA == 'G')
        {
            tujuanX = 7;
        }
        else if(tujuanA == 'H')
        {
            tujuanX = 8;
        }
        chess(x, y, tujuanX, tujuanY, sum);
        printf("Case #%d: %d\n",i, jum);
        sum = 0;
        jum = 0;
    }
    return 0;
}