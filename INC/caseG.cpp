#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, m;
    scanf("%lld %lld", &n, &m);
    getchar();
    char a, b;
    long long int val1, val2;
    long long int max = m;
    long long int min = m;
    for (int i = 0; i < n; i++)
    {
        long long int maxround = max;
        long long int minround = min;
        scanf("%c %lld %c %lld", &a, &val1, &b, &val2);
        getchar();
        if (a == 'x')
        {
            long long int temp1 = val1 * max;
            maxround = temp1;
            minround = temp1;
            long long int temp2 = val1 * min;
            if (maxround < temp2)
            {
                maxround = temp2;
            }
            if (minround > temp2)
            {
                minround = temp2;
            }
        }
        else if (a == '+')
        {
            long long int temp1 = val1 + max;
            maxround = temp1;
            minround = temp1;
            long long int temp2 = val1 + min;
            if (maxround < temp2)
            {
                max = temp2;
            }
            if (minround > temp2)
            {
                minround = temp2;
            }
        }

        if (b == 'x')
        {
            long long int temp1 = val2 * max;
            if (maxround < temp1)
            {
                maxround = temp1;
            }
            if (minround > temp1)
            {
                minround = temp1;
            }
            long long int temp2 = val2 * min;
            if (maxround < temp2)
            {
                maxround = temp2;
            }
            if (minround > temp2)
            {
                minround = temp2;
            }
        }
        else if (b == '+')
        {
            long long int temp1 = val2 + max;
            if (maxround < temp1)
            {
                maxround = temp1;
            }
            if (minround > temp1)
            {
                minround = temp1;
            }
            long long int temp2 = val2 + min;
            if (maxround < temp2)
            {
                maxround = temp2;
            }
            if (minround > temp2)
            {
                minround = temp2;
            }
        }
        max = maxround;
        min = minround;
    }
    printf("%lld\n", max);
    return 0;
}