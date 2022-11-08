#include<stdio.h>

int main()
{
  long long int a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3,jumlah1,jumlah2,jumlah3;

  scanf("(%lld+%lld)x(%lld-%lld)", &a1, &b1, &c1, &d1); getchar();
  scanf("(%lld+%lld)x(%lld-%lld)", &a2, &b2, &c2, &d2); getchar();
  scanf("(%lld+%lld)x(%lld-%lld)", &a3, &b3, &c3, &d3); getchar();

  jumlah1 = (a1+b1)*(c1-d1);
  jumlah2 = (a2+b2)*(c2-d2);
  jumlah3 = (a3+b3)*(c3-d3);
  
  printf("%lld %lld %lld\n",jumlah1,jumlah2,jumlah3);
  return 0;
}
