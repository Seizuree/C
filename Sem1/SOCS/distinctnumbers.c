#include <stdio.h>

int main()
{
  int percobaan;
  scanf("%d",&percobaan); getchar();
  for(int i = 0; i < percobaan; i++)
  {
    int ukr;
    scanf("%d",&ukr); getchar();
    int arr[ukr+1];
    char count[1000001] = {0};
    for(int j = 0; j < ukr; j++)
    {
      scanf("%d",&arr[j]); getchar();
      count[arr[j]] = 1;
    }
    int jumm = 0;
    for (int j = 0; j < 1000001; j++)
    {
      if(count[j] == 1)
      {
        jumm += 1;
      }
    }
    
    printf("Case #%d: %d\n",i+1,jumm);
  }
  return 0;
}

