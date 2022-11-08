#include <stdio.h>

char arr2d[200][200];
int sum = 0;

void floodfill(int x, int y)
{
    if(arr2d[x][y] == '#' || arr2d[x][y] == '\n' || arr2d[x][y] == '\0')
    {
        return;
    }
    else if(arr2d[x][y] == '*')
    {
        sum++;
    }

    arr2d[x][y] = '#';

    floodfill(x+1,y);
    floodfill(x-1,y);
    floodfill(x,y+1);
    floodfill(x,y-1);
}

int main()
{
    int bnyk;
    scanf("%d",&bnyk); getchar();
    for(int p = 1; p <= bnyk; p++)
    {
        int m, n;
        scanf("%d %d",&m,&n); getchar();
        int row, column;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%c",&arr2d[i][j]);
                if(arr2d[i][j] == 'P')
                {
                    row = i;
                    column = j;
                }
            }
            getchar();
        }

        floodfill(row, column);

        printf("Case #%d: %d\n",p,sum);
        sum = 0;
        m = 0;
        n = 0;

        for (int s = 0; s < 200; s++)
        {
            for(int t = 0; t < 200; t++)
            {
                arr2d[s][t] = '\0';
            }
        }
    }
    return 0;
}