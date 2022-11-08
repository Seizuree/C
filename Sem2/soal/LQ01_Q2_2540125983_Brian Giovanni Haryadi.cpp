#include <stdio.h>
#include <stdlib.h>

int arr[50];
int ukuran = -1;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int curr)
{
    return (curr - 1) / 2;
}

int leftChild(int curr)
{
    return ((2 * curr) + 1);
}

int rightChild(int curr)
{
    return ((2 * curr) + 2);
}

void shiftUp(int curr)
{
    while (curr > 0 && arr[parent(curr)] < arr[curr]) {
        swap(&arr[parent(curr)], &arr[curr]);
        curr = parent(curr);
    }
}

void shiftDown(int curr)
{
    int maxIndex = curr;
    int left = leftChild(curr);
    if (left <= ukuran && arr[left] > arr[maxIndex]) {
        maxIndex = left;
    }
    int right = rightChild(curr);
    if (right <= ukuran && arr[right] > arr[maxIndex]) {
        maxIndex = right;
    }
    if (curr != maxIndex) {
        swap(&arr[curr], &arr[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p)
{
    ukuran = ukuran + 1;
    arr[ukuran] = p;
    shiftUp(ukuran);
}

int extractMax()
{
    int result = arr[0];
    arr[0] = arr[ukuran];
    ukuran = ukuran - 1;
    shiftDown(0);
    return result;
}

void changePriority(int curr, int p)
{
    int oldPriority = arr[curr];
    arr[curr] = p;
    if (p > oldPriority) {
        shiftUp(curr);
    }
    else {
        shiftDown(curr);
    }
}

int getMaxNode()
{
    return arr[0];
}

void remove(int curr)
{
    arr[curr] = getMaxNode() + 1;
    shiftUp(curr);
    extractMax();
}
int main()
{
    int choices = 0;
    do
    {
        system("cls");
        printf("1. Insert\n");
        printf("2. Print Node with max priority\n");
        printf("3. Remove\n");
        printf("4. Print Queue\n");
        scanf("%d",&choices); getchar();
        if (choices == 1)
        {
            system("cls");
            int tempNum = 0;
            printf("Insert a number : ");
            scanf("%d",&tempNum); getchar();
            insert(tempNum);
            tempNum = 0;
            printf("Node successfully inserted."); getchar();
            main();
        }
        else if (choices == 2)
        {
            int temp2 = extractMax();
            system("cls");
            printf("Node with max priority : %d",temp2);
            getchar();
            main();
        }
        else if (choices == 3)
        {
            int temp3 = 0;
            system("cls");
            printf("Input a number to be removed : ");
            scanf("%d",&temp3); getchar();
            remove(temp3);
            printf("Node have been removed\n"); getchar();
            main();
        }
        else if (choices == 4)
        {
            system("cls");
            for (int i = 0; i < ukuran; i++)
            {
                printf("%d ",arr[i]);
            }
        }       
    } while (choices < 1 || choices > 4);
    return 0;
}