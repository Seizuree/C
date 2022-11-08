#include <stdio.h>

int main()
{
    int count;
    scanf("%d",&count); getchar(); // scan banyaknya angka yang akan diuji
    long long int arr1[count+5];
    for (int i = 0; i < count; i++)
    {
        scanf("%lld",&arr1[i]); getchar(); // scan angka yang akan diuji
    }
    int temp = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr1[i] + arr1[i+1] > arr1[i+2] && arr1[i] + arr1[i+2] > arr1[i+1] && arr1[i+1] + arr1[i+2] > arr1[i]) // rumus segitiga
        {
            temp = 1; // temp bernilai 1 apabila fungsi diatas berhasil
        }
    }
    
    if (temp == 1) // apabila bernilai 1 berarti akan print YES
    {
        printf("YES\n");
    }
    else // selain bernilai 1 akan print NO
    {
        printf("NO\n");
    }
    
    return 0;
}