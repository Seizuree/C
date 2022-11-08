#include <stdio.h>
#include <stdlib.h>

int heap[105] = {0};
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void upHeap(int index)
{
    if(index == 1)
        return;
    int parent = index / 2;
    if(heap[parent] > heap[index])
    {
        swap(&heap[parent], &heap[index]);
        upHeap(parent);
    }
}

void downHeap(int index)
{
    int curr = index;

    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;

    if (leftChild <= size && heap[curr] > heap[leftChild])
    {
        curr = leftChild;
    }

    if (rightChild <= size && heap[curr] > heap[rightChild])
    {
        curr = rightChild;
    }

    if (curr == index)
    {
        return;
    }
    swap(&heap[curr], &heap[index]);

    downHeap(curr);
}

void insertHeap(int value)
{
    size += 1;
    heap[size] = value;
    upHeap(size);
}

void printHeap()
{
    for (int i = 1; i <= size ; i++)
    {
        printf("%d",heap[i]);
        i == size ? printf("\n") : printf(" | ");
    }
}

void printTree()
{
    for (int i = 1; i <= size / 2; i++)
    {
        printf("Parent : %d, left child: %d, right child: %d\n",heap[i], heap[2*i], heap[2*i + 1]);
    }
}

int extractRoot()
{
    if(size == 0)
    {
        printf("Heap is empty\n");
        getchar;
        return 0;
    }
    if(size == 1)
    {
        size -= 1;
        return heap[1];
    }
    
    int returnValue = heap[1];
    swap(&heap[1], &heap[size]);
    size -= 1;
    downHeap(1);
    return returnValue;
}

int main()
{
    insertHeap(50);
    insertHeap(100);
    insertHeap(150);
    insertHeap(30);
    printHeap();
    puts("");
    printTree();
    extractRoot();
    puts("");
    printHeap();
    puts("");
    printTree();
}