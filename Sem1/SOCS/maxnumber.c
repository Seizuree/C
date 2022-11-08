#include <stdio.h>

int main()
{
  int jum1, jum2;
  scanf("%d %d", &jum1, &jum2);
  getchar();
  int arr1[jum1];
  int arr2[jum2];
  int min = 0;
  for(int i = 0 ; i< jum1; i++)
  {
    scanf("%d", &arr1[i]);
    getchar();
  }
  for(int i = 0 ; i < jum2; i++)
  {
    scanf("%d", &arr2[i]);
    getchar();
  }

  for(int i = 0 ; i < jum2 ;i++)
  {
    for(int j = 0 ; j < jum1 ; j++)
    {
      if(arr2[i] == arr1[j])
      {
        arr1[j] = 0;
      }
    }
    
  }

  int num, cek;
  for(int i = 0 ; i < jum1; i++)
  {
    if(arr1[i] == arr1[i+1])
    {
      cek = -1;
    }
    else
    {
      cek = 1;
    }
  }

  for(int i = 0 ; i < jum1; i++)
  {
    if(arr1[i] > min)
    {
      num = arr1[i];
      min = num;
    }
  }
  if(jum1 <= 0 || cek == -1)
  {
    printf("Maximum number is -1\n");
  }
  else
  {
    printf("Maximum number is %d\n", num);
  }

  return 0;
}