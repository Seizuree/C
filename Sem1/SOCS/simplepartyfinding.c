#include <stdio.h>

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int sizeArr1 = m - l + 1;
    int sizeArr2 = r - m;
    int arr1[sizeArr1], arr2[sizeArr2];
    
    for (int i = 0; i < sizeArr1; i++)
    {
        arr1[i] = arr[l + i];
    }
    for (int j = 0; j < sizeArr2; j++)
    {
        arr2[j] = arr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    
    while (i < sizeArr1 && j < sizeArr2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < sizeArr1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    
    while (j < sizeArr2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// int binarySearch(int *arr, int l, int r, int search)
// {
//     if (r >= l)
//     {
//         int mid = l + (r - l) / 2;
//         if (arr[mid] == search)
//         {
//             return mid;
//         }

//         if (arr[mid] > search)
//         {
//             return binarySearch(arr,l,mid-1,search);
//         }
//         return binarySearch(arr, mid+1, r,search);
//     }
//     return -1;
// }

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // if we reach here, then element was
    // not present
    return -1;
}

int main()
{
    int count;
    scanf("%d",&count); getchar();
    for (int i = 1; i <= count; i++)
    {
        int players;
        scanf("%d",&players); getchar();
        int arr1[players+5];
        for (int j = 0; j < players; j++)
        {
            scanf("%d",&arr1[j]); getchar();
        }
        int partyMMR;
        scanf("%d",&partyMMR); getchar();
        mergeSort(arr1, 0, players-1);
        int index = binarySearch(arr1,0,players-1,partyMMR);

        if (index == -1)
        {
            printf("CASE #%d: -1 -1\n",i);
        }
        else if (index == players-1)
        {
            printf("CASE #%d: %d %d\n",i, arr1[index-1], partyMMR);
        }
        else
        {
            printf("CASE #%d: %d %d\n",i,partyMMR,arr1[index+1]);
        }
    }
    return 0;
}