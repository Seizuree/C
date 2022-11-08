#include <stdio.h>

int main()
{
  int bnyk;
  scanf("%d",&bnyk); getchar();
  for (int i = 0; i < bnyk; i++)
  {
    long long int angka1;
    int sisaBagi;
    scanf("%lld",&angka1); getchar();
    int res[151] = {};
    int x = 0;
    for(long long int j = angka1; j > 0; j/= 2)
    {
      sisaBagi = j % 2;
      res[x] = sisaBagi;
      ++x;
    }
    printf("Case #%d: ",i+1);
    for(long long int i = x - 1; i >= 0; i--)
    {
      printf("%d",res[i]);
    }
    printf("\n");
  }
  return 0;
}
