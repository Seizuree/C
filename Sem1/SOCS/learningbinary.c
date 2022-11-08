#include <stdio.h>

int main()
{
    int testcase;
    scanf("%d",&testcase);
    int arr[35]={0};
    int temp;
    for(int i = 0; i < testcase; i++)
    {
        int angka1,angka2;
        scanf("%d %d",&angka1,&angka2);
        for(int j = 0; angka1 > 0; j++)
        {
            arr[j] = angka1 % 2;
            angka1 = angka1 / 2;
        }
        printf("%d\n",arr[angka2]);
    }
}