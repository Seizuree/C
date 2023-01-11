#include <stdio.h>

int T[200001] = {0};

int main()
{
    int Q, x;
    char symbol;
    scanf("%d", &Q);
    getchar();
    int N = 0;
    for (int i = 0; i < Q; i++)
    {
        scanf("%c %d", &symbol, &x);
        getchar();
        if (symbol == '+')
        {
            T[x] += 1;
            if (T[x] == 0)
            {
                N--;
            }
            else if (T[x] == 1)
            {
                N++;
            }
            while (T[x] == 2)
            {
                T[x] = 0;
                N -= 1;
                x += 1;
                T[x] += 1;
                if (T[x] == 0)
                {
                    N--;
                }
                else if (T[x] == 1)
                {
                    N++;
                }
            }
        }
        else if (symbol == '-')
        {
            T[x] -= 1;
            if (T[x] == 0)
            {
                N--;
            }
            else if (T[x] == -1)
            {
                N++;
            }
            while (T[x] == -2)
            {
                T[x] = 0;
                N -= 1;
                x += 1;
                T[x] -= 1;
                if (T[x] == 0)
                {
                    N--;
                }
                else if (T[x] == -1)
                {
                    N++;
                }
            }
        }
        if (N == 0)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
