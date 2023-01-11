#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int p, q;
    scanf("%lld %lld", &p, &q);
    getchar();
    char a, b;
    long long int x, y;
    long long int max = q;
    long long int min = q;
    for (int i = 0; i < p; i++)
    {
        long long int maxcalc = max;
        long long int mincalc = min;
        scanf("%c %lld %c %lld", &a, &x, &b, &y);
        getchar();
        if (a == 'x')
        {
            long long int temp1 = x * max;
            maxcalc = temp1;
            mincalc = temp1;
            long long int temp2 = x * min;
            if (maxcalc < temp2)
            {
                maxcalc = temp2;
            }
            if (mincalc > temp2)
            {
                mincalc = temp2;
            }
        }
        else if (a == '+')
        {
            long long int temp1 = x + max;
            maxcalc = temp1;
            mincalc = temp1;
            long long int temp2 = x + min;
            if (maxcalc < temp2)
            {
                max = temp2;
            }
            if (mincalc > temp2)
            {
                mincalc = temp2;
            }
        }

        if (b == 'x')
        {
            long long int temp1 = y * max;
            if (maxcalc < temp1)
            {
                maxcalc = temp1;
            }
            if (mincalc > temp1)
            {
                mincalc = temp1;
            }
            long long int temp2 = y * min;
            if (maxcalc < temp2)
            {
                maxcalc = temp2;
            }
            if (mincalc > temp2)
            {
                mincalc = temp2;
            }
        }
        else if (b == '+')
        {
            long long int temp1 = y + max;
            if (maxcalc < temp1)
            {
                maxcalc = temp1;
            }
            if (mincalc > temp1)
            {
                mincalc = temp1;
            }
            long long int temp2 = y + min;
            if (maxcalc < temp2)
            {
                maxcalc = temp2;
            }
            if (mincalc > temp2)
            {
                mincalc = temp2;
            }
        }
        max = maxcalc;
        min = mincalc;
    }
    printf("%lld\n", max);
    return 0;
}