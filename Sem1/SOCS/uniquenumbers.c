#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int a1 = m - l + 1;
    int a2 = r - m;

    int arr1[a1], arr2[a2];
    for (int i = 0; i < a1; i++)
    {
        arr1[i] = arr[l+i];
    }
    for (int j = 0; j < a2; j++)
    {
        arr2[j] = arr[m+1+j];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < a1 && j < a2)
    {
        if(arr1[i] <= arr2[j])
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
    
    while (i < a1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    
    while (j < a2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    
}

int main()
{
	int x;
	scanf("%d", &x);
	int arr[x];
	for(int i = 0; i < x; i++)
	{
		scanf("%d", &arr[i]);
	}
	mergeSort(arr, 0, x-1);
	int cek = 1;
	for(int i = 1; i < x; i++)
	{
		if(arr[i] != arr[i-1]) 
        {
            cek++;
        }
	}
	printf("%d\n", cek);
	return 0;
}

