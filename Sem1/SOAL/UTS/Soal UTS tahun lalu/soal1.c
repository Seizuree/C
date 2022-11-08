#include <stdio.h>
#include <math.h>

int main()
{
  float sum = 0;
  float pajak = 0;
  float bersihTahun = 0;
  float keuntunganBersih = 0;
  float a[14];
  for(int i = 0; i < 12; i++)
  {
    scanf("%f",&a[i]); getchar();
  }
  for (int i = 0; i < 12; i++)
  {
    sum += a[i];
  }
  pajak = floorf(sum * 7/100);
  bersihTahun = floorf(sum * 5/100);
  keuntunganBersih = sum - pajak - bersihTahun;
  printf("%.2f, %.2f, %.2f\n",pajak,bersihTahun,keuntunganBersih);
  return 0;
}
