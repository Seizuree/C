// #include <stdio.h>

// int main()
// {
//     int testcase;
//     scanf("%d",&testcase); getchar();
//     for(int i = 0; i < testcase; i++)
//     {
//         int jumlahAngka = 0;
//         int minArr = 0;
//         scanf("%d",&jumlahAngka); getchar();
//         int arr1[jumlahAngka+1];
//         for(int j = 0; j < jumlahAngka; j++)
//         {
//             scanf("%d",&arr1[j]);
//         }
//         for(int j = 0; j < jumlahAngka; j++)
//         {
//             minArr -= arr1[j];
//             if(minArr == arr1[j])
//         }
//     }
// }

#include <stdio.h>

int main(){
    int testcase;
    scanf("%d",&testcase); getchar();
    for(int i = 0; i < testcase;i++)
    {
        int ukur = 0;
        scanf("%d", &ukur); getchar();
        int arr1[ukur+5];
        for(int j = 0; j < ukur;j++)
        {    
            scanf("%d", &arr1[j]); getchar();     
        }
        long long int temp = 10000000000;
        for(int j = 0; j < ukur; j++)
        {
            for(int k = j + 1; k < ukur; k++)
            {
                int hasil = arr1[j] - arr1[k];
                if(hasil < 0)
                {
                    hasil*=-1;
                }
                if(hasil < temp)
                {
                    temp = hasil;
                }
            }
        }
        printf("%lld", temp);
        printf("\n");
    }
    return 0;
}