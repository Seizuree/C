#include <stdio.h>

unsigned long long counter(unsigned long long int mid){
    return (mid)*(mid+1)*(2*mid+1)/6;
}

unsigned long long binary(unsigned long long int left, unsigned long long int right, unsigned long long int m){
    if(left <= right){
        unsigned long long mid = (right+left)/2;
        if(counter(mid) >= m){ // counter[mid] <= m return
            return binary(left, mid-1, m);
        }else{
            return binary(mid+1, right, m);
        }
    }
    return left;
}

int main(){
    int bnyk;
    unsigned long long int m;
    scanf("%d", &bnyk); getchar();
    for(int i = 1; i <= bnyk; i++){
        scanf("%llu", &m);
        printf("Case #%d: %llu\n", i, binary(1, 10000005, m));
    }
}
