#include <stdio.h>

int binarySearch(int findPos, int n, int *num)
{
  int last = n - 1;
  int first = 0;
  int mid = 0;

  while (first <= last)
  {
    mid = (first + last) / 2;
    if(num[mid] < findPos)
    {
      first = mid + 1;
    }
    else if (num[mid] > findPos)
    {
      last = mid - 1;
    }
    else if(num[mid - 1] == findPos && mid > 0)
    {
      last = mid;
    }
    else if(num[mid] == findPos)
    {
      return mid;
    }
  }
  return -1;
}

int main()
{
  int a,b;
  int num[100001], findPos[100001];
  scanf("%d %d",&a,&b); getchar();
  for (int i = 0; i < a; i++)
  {
    scanf("%d",&num[i]); getchar();
  }
  for (int j = 0; j < b; j++)
  {
    scanf("%d",&findPos[j]); getchar();
  }

  for (int i = 0; i < b; i++)
  {
    int res = binarySearch(findPos[i],a,num);
    if (res == -1)
    {
      printf("-1\n");
    }
    else
    {
      printf("%d\n",res+1);
    }
  }
}
