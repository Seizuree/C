// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     int count;
//     scanf("%d",&count); getchar();
//     for (int i = 0; i < count; i++)
//     {
//         int bnyk, pilihan;
//         scanf("%d %d",&bnyk,&pilihan); getchar();
//         char nama[100][100];
//         for (int j = 0; j < bnyk; j++)
//         {
//             scanf("%s",&nama[j]); getchar();
//         }
//         for (int j = 0; j < bnyk; j++)
//         {
//             for (int k = 0; k < bnyk-1-j; k++)
//             {
                
//                 if (strcmp(nama[k], nama[k+1]) > 0)
//                 {
//                     char temp[100];
//                     strcpy(temp, nama[k]);
//                     strcpy(nama[k], nama[k+1]);
//                     strcpy(nama[k+1], temp);
//                 }                
//             }
//         }
//         printf("Case #%d: %s",i+1,nama[pilihan-1]);   
//     }   
// }

#include <stdio.h>

void merge(int arr[], int a, int m, int b)
{
    int a1 = m - a + 1;
    int a2 = b - m;

    int L[a1], R[a2];

    for (int i = 0; i < a1; i++)
    {
        L[i] = arr[a + i];
    }
    for (int j = 0; j < a2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    
    int i = 0;
    int j = 0;
    int k = a;
    
    while (i < a1 && j < a2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < a1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < a2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int a, int b)
{
    if (a < b)
    {
        int m = a + (b - a) / 2;
        mergeSort(arr, a, m);
        mergeSort(arr, m+1, b);

        merge(arr, a, m, b);
    }
}

int binarySearch(int arr[], int a, int b, int x)
{
    if (b >= a)
    {
        int mid = a + (b-a) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            return binarySearch(arr, a, mid - 1, x);
        }
        return binarySearch(arr,mid+1,b,x);
    }
}

int main()
{
    int count;
    scanf("%d",&count); getchar();
    for (int x = 0; x < count; x++)
    {
        int banyak;
        scanf("%d",&banyak); getchar();
        int mmr[banyak+5];
        for (int i = 0; i < banyak; i++)
        {
            scanf("%d",&mmr[i]); getchar();
        }
        int findmmr;
        scanf("%d",&findmmr); getchar();
        mergeSort(mmr, 0, banyak-1);
        int searched = binarySearch(mmr, 0, banyak-1, findmmr);
        if (searched == -1)
        {
            printf("CASE #%d: -1 -1\n",x+1);
        }
        else if (searched == banyak-1)
        {
            printf("CASE #%d: %d %d\n",x+1,mmr[searched-1], findmmr);
        }
        else
        {
            printf("CASE #%d: %d %d\n",x+1,findmmr,mmr[searched+1]);
        }
        
    }
    
}
