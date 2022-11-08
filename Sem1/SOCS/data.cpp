#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Orang
{
  char nama[100];
  int nomor;
};

int main()
{
  int tc;
  scanf("%d\n",&tc);

  for (int x = 0; x < tc; x++)
  {
    int tc1;
    scanf("%d\n",&tc1);
    struct Orang arr[tc1];
    for (int y = 0; y < tc1; y++)
    {
      scanf("%[^#]#%d",arr[y].nama, &arr[y].nomor); getchar();
    }
    for (int j = 0; j < tc1; j++)
    {
      for (int k = 0; k < tc1-1-j; k++)
      {
        if(arr[k].nomor > arr[k+1].nomor)
        {
          Orang temp = arr[k];
          arr[k] = arr[k+1];
          arr[k+1] = temp;
        }
        else if(arr[k].nomor == arr[k+1].nomor && strcmp(arr[k].nama, arr[k+1].nama) > 0)
        {
          Orang temp = arr[k];
          arr[k] = arr[k+1];
          arr[k+1] = temp;
        }
        
      }
    }
    printf("Case #%d:\n",x+1);
    for (int j = 0; j < tc1; j++)
    {
      printf("%s - %d\n",arr[j].nama, arr[j].nomor);
    }
  }
  return 0;
}
