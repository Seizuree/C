#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, m;
    scanf("%lld %lld", &n, &m); getchar();
    char a, b;
    long long int val1, val2;
    long long int max = m;
    long long int min = m;
    for(int i=0; i<n;i++){
        long long int x = max;
        long long int y = min;
        scanf("%c %lld %c %lld", &a, &val1, &b, &val2);getchar();
        if(a == 'x'){
            long long int temp1 = val1*max;
            x = temp1;
            y = temp1;
            long long int temp2 = val1*min;
            if(x<temp2) x =temp2;
            if(y>temp2) y = temp2;
        }
        else if(a == '+')
        {
            long long int temp1 = val1+max;
            x = temp1;
            y = temp1;
            long long int temp2 = val1+min;
            if(x<temp2) max = temp2;
            if(y>temp2) y = temp2;
        }
        
        if(b == 'x')
        {
            long long int temp1 = val2*max;
            if(x<temp1) x = temp1;
            if(y>temp1) y = temp1;
            long long int temp2 = val2*min;
            if(x<temp2) x = temp2;
            if(y>temp2) y = temp2;
        }
        else if(b == '+')
        {
            long long int temp1 = val2+max;
            if(x<temp1) x =temp1;
            if(y>temp1) y = temp1;
            long long int temp2 = val2+min;
            if(x<temp2) x =temp2;
            if(y>temp2) y = temp2;
        }
        max = x;
        min = y;
    }
    printf("%lld\n", max);
    return 0;
}