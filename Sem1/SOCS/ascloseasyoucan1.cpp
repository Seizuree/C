#include <stdio.h>

unsigned long long int binarySearchCount(unsigned long long int arr[],unsigned long long int n, unsigned long long int key)
{
  unsigned long long int left = 1;
  unsigned long long int right = n;

  unsigned long long int mid = 0;
  while (left < right)
  {
      mid = left+(right - left) / 2;
       // if (arr[mid] == key)
       // {
       //    while (mid + 1 < n && arr[mid + 1] == key)
       //          mid++;
       //          left = mid;
       //      	break;
       // }
      if (arr[mid] > key)
          right = mid-1;
      else
          left = mid+1;
  }

while (arr[left]>key)
      left-=1;

    return left;
}

int main()
{
  unsigned long long int a;
  scanf("%llu",&a); getchar();
  unsigned long long int arr1[a+1]={};
  for(int i = 1; i <= a; i++)
  {
    scanf("%llu",&arr1[i]); getchar();
    arr1[i] = arr1[i]+arr1[i-1];
  }
  int b;
  scanf("%d",&b); getchar();
  for(int i = 1; i <= b; i++)
  {
    unsigned long long int angka = 0;
    scanf("%llu",&angka); getchar();
    if(angka < arr1[1])
    {
      printf("Case #%d: -1\n",i);
    }
    else if (angka >= arr1[a]) {
      printf("Case #%d: %d\n",i,a);
    }
    else
    {
      printf("Case #%d: %llu\n",i,binarySearchCount(arr1,a,angka));
    }
  }
  return 0;
}
