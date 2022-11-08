#include <stdio.h>

int main()
{
  int tc;
  scanf("%d",&tc); getchar();
  unsigned long long int jumPis = 0;
  unsigned long long int beratMin = 0;
  for (int i = 0; i < tc; i++)
  {
    scanf("%llu %llu",&jumPis,&beratMin); getchar();
    unsigned long long int pisang[jumPis+5];
    unsigned long long int counter = 0;
    for (int j = 0; j < jumPis; j++)
    {
      scanf("%llu",&pisang[j]); getchar();
      if(pisang[j] >= beratMin)
      {
        counter++;
      }
    }
    printf("Case #%d: %d\n",i+1,counter);
  }
  return 0;
}
