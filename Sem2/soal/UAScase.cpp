#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cafe{
    int amount = 0;
    char name[150];
};
int ukuran = 0;

void swap(Cafe *a, Cafe *b)
{
    Cafe temp = *a;
    *a = *b;
    *b = temp;
}

void heapShifting(Cafe product[], int index)
{
    int leftC = 2 * index + 1;
    int rightC = 2 * index + 2;
    int largest = index;
    if (leftC < ukuran && product[leftC].amount > product[largest].amount)
    {
        largest = leftC;
    }
    if (rightC < ukuran && product[rightC].amount > product[largest].amount)
    {
        largest = rightC;
    }
    if (largest != index)
    {
        swap(&product[largest], &product[index]);
        heapShifting(product, largest);
    }
}

void insert(Cafe product[], char productName[], int amount)
{
    int penanda = 0;
    int i = 0;
    for (i = 0; i < ukuran; i++)
    {
        if (strcmp(productName, product[i].name) == 0)
        {
            product[i].amount += amount;
            penanda = 1;
        }
    }
    if (penanda == 0)
    {
        product[ukuran].amount = amount;
        strcpy(product[ukuran].name, productName);
        ukuran += 1;
    }
    else
    {
        product[i].amount += amount;
    }
    if (ukuran > 0 || i > 0)
    {
        for (int i = (ukuran / 2 - 1); i >= 0; i--)
        {
            heapShifting(product, i);
        }
    }
}

void printTopSales(Cafe product[])
{
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(product[i].name, "BC") == 0)
        {
            printf("%d. Boba Coffee %d\n",i+1, product[i].amount);
        }
        else if (strcmp(product[i].name, "MC") == 0)
        {
            printf("%d. Moccapucino %d\n",i+1, product[i].amount);
        }
        else if (strcmp(product[i].name, "PC") == 0)
        {
            printf("%d. Pandan Coffee %d\n",i+1, product[i].amount);
        }
        else if (strcmp(product[i].name, "BT") == 0)
        {
            printf("%d. Boba Thai %d\n",i+1, product[i].amount);
        }
        else if (strcmp(product[i].name, "CP") == 0)
        {
            printf("%d. Choco Pandan %d\n",i+1, product[i].amount);
        }
        else if (strcmp(product[i].name, "CC") == 0)
        {
            printf("%d. Cheese Choco %d\n",i+1, product[i].amount);
        }
    }
}

int main()
{
    struct Cafe product[150];
    int count = 0;
    scanf("%d",&count); getchar();
    while(count--)
    {
        char productName[150];
        int amount = 0;
        scanf("%d %s",&amount, &productName); getchar();
        insert(product,productName, amount);
    }
    printf("Top Sales:\n");
    printTopSales(product);
    return 0;
}