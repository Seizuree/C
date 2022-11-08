#include <stdio.h>

int main()
{
  int bnyk;
  scanf("%d",&bnyk); getchar();
  unsigned long long int boss[bnyk+5];
  unsigned long long int p1 = 0;
  unsigned long long int temp = 0;
  unsigned long long int ctr = 0;
  for(int i = 0; i < bnyk; i++)
  {
    scanf("%llu",&boss[i]); getchar();
  }

  for (int i = 0; i < bnyk-1; i++)
  {
      for (int j = 0; j < bnyk-1; j++)
      {
        if(boss[j] > boss[j+1])
        {
          temp = boss[j+1];
          boss[j+1] = boss[j];
          boss[j] = temp;
        }
      }
  }
  scanf("%llu",&p1); getchar();

  for (int i = 0; i < bnyk; i++)
  {
    if(boss[i] < p1 || boss [i] == p1)
    {
      ctr++;
      p1 = p1 - boss[i];
    }
  }

  printf("%d\n",ctr);
  return 0;
}
