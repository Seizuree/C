#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
const int size = 100;

char tempProdID[50] = {};
char tempDate[50] = {};
int totalData = 0;

struct Node
{
    char name[100];
    long long int price = 0;
    long long int stock = 0;
    char expiredDate[30];
    char productID[10];
    Node *next;
};

Node* createData(const char name[], long long int price, long long int stock, const char expiredDate[], const char productID[])
{
    Node *newData = (Node *)malloc(sizeof(Node));
    strcpy(newData->name, name);
    newData->price = price;
    newData->stock = stock;
    strcpy(newData->expiredDate, expiredDate);
    strcpy(newData->productID, productID);
    newData->next = NULL;

    return newData;
}

Node *hash[size];

void expDate()
{
    int date = rand() % (30 - 1) + 1;
    int month = rand() % (12 - 1) + 1;
    int year = rand() % (25 - 20) + 20;
    sprintf(tempDate, "%d/%d/%d",date,month,year);
}

void createProductID(const char category[])
{
    for (int i = totalData+1; i <= 100; i++)
    {
        if (category[0] == 'H' || category[0] == 'F' || category[0] == 'D')
        {
            if (i < 100)
            {
                sprintf(tempProdID,"%c%03d",category[0],i);
                break;
            }
            if (i < 10)
            {
                sprintf(tempProdID,"%c%02d",category[0],i);
                break;
            }
            if(i == 100)
            {
                sprintf(tempProdID,"%c%d",category[0],i);
                break;
            }
        }
    }
}

void clearTemp(char target[])
{
    for (int i = 0; i < strlen(target); i++)
    {
        target[i] = '\0';
    }
}

int hashing(const char prodID[])
{
    int key = 0;
    key = (prodID[0] * (prodID[3] + prodID[1] - prodID[2]) % size);
    return key;
}

void insertData(const char name[], long long int price, long long int stock, const char expiredDate[], const char productID[])
{
    int key = hashing(productID);
    Node *insert = createData(name, price, stock, expiredDate, productID);
    if (hash[key] == NULL)
    {
        hash[key] = insert;
    }
    else
    {
        Node *curr = hash[key];
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = insert;
    }
    totalData++;
}

void addNewProd()
{
    srand(time(NULL));
    char prodName[100];
    long long int prodPrice = 0;
    long long int prodStock = 0;
    char prodCategory[30];
    int checkCat = 0;
    do
    {
        printf("Insert Product Name [Product name must be more than 5 characters]: ");
        scanf("%[^\n]",&prodName); getchar();
    } while (strlen(prodName) < 6);
    do
    {
        printf("Insert Product Price [1 - 150000 (inclusive)]: ");
        scanf("%lld",&prodPrice); getchar();
    } while (prodPrice < 0 || prodPrice > 150000);
    do
    {
        printf("Insert Product Stock [more than 0]: ");
        scanf("%lld",&prodStock); getchar();
    } while (prodStock < 0);
    do
    {
        printf("Insert Product Category [Health | Food | Digital] (case sensitive) : ");
        scanf("%[^\n]",&prodCategory); getchar();
        if (strcmp(prodCategory, "Health") == 0 || strcmp(prodCategory, "Food") == 0 || strcmp(prodCategory, "Digital") == 0)
        {
            checkCat++;
        }
    } while (checkCat < 0 || checkCat == 0);
    if (strcmp(prodCategory, "Digital") == 0)
    {
        strcpy(tempDate, "-");
    }
    else
    {
        expDate();
    }
    createProductID(prodCategory);
    insertData(prodName, prodPrice, prodStock, tempDate, tempProdID);
    clearTemp(tempDate);
    clearTemp(tempProdID);
    printf("Successfully Added New Product\n");
}

int search(const char prodID[])
{
    int key = hashing(prodID);
    Node *temp = hash[key];
    if (strcmp(temp->productID, prodID) == 0)
    {
        return 1;
    }
    else
    {
        while (temp != NULL)
        {
            if (strcmp(temp->productID, prodID) == 0)
            {
                return 1;
            }
            temp = temp->next;
        }
    }
    return 0;
}

void delProd()
{
    char tempDel[100];
    int validateInput = 0;
    do
    {
        printf("Input Product ID to delete : ");
        scanf("%s",tempDel); getchar();
        if (tempDel[0] == 'H' || tempDel[0] == 'F' || tempDel[0] == 'D')
        {
            validateInput++;
        }
    } while (validateInput == 0 || validateInput < 0);
    int key = hashing(tempDel);
    char deleteConfirm;
    int found = search(tempDel);
    validateInput = 0;
    if (found == 1)
    {
        do
        {
            printf("Sure to delete %s ? [Y/N] (case insensitive) : ",tempDel);
            scanf("%c",&deleteConfirm); getchar();
            if (deleteConfirm == 'Y' || deleteConfirm == 'y' || deleteConfirm == 'N' || deleteConfirm == 'n')
            {
                validateInput++;
            }
        } while (validateInput == 0 || validateInput < 0);
        if (deleteConfirm == 'Y' || deleteConfirm == 'y')
        {
            if (strcmp(hash[key]->productID, tempDel) == 0)
            {
                Node *deleted = hash[key];
                hash[key] = hash[key]->next;
                deleted = NULL;
                free(deleted);
            }
            else
            {
                Node *temp = hash[key];
                while (strcmp(temp->next->productID, tempDel) == 0 && temp->next != NULL)
                {
                    temp = temp->next;
                }
                Node *deleted = temp->next;
                temp->next = deleted->next;
                deleted = NULL;
                free(deleted);
            }
            printf("Sucessfully Delete Product\n");
            totalData--;
            getchar();
            return;
        }
    }
    else if(found == 0)
    {
        printf("Data Not Found\n");
        getchar();
        return;
    }
}

void printTable()
{
    for (int i = 0; i < size; i++)
    {
        Node *temp = hash[i];
        while(temp != NULL)
        {
            printf("Product ID : %s\n",temp->productID);
            printf("===============\n");
            printf("Product Name : %s\n",temp->name);
            printf("Product Price : %lld\n",temp->price);
            printf("Product Stock : %lld\n",temp->stock);
            printf("Expired Date : %s\n\n",temp->expiredDate);
            temp = temp->next;
        }
    }
}

int main()
{
    int choices = 0;
    do
    {
        system("cls");
        if (totalData == 0)
        {
            printf("No Product Yet\n\n");
        }
        else
        {
            system("cls");
            printTable();
            printf("\n");
        }
        puts("Mini SO");
        puts("=======");
        puts("1. Add New Product");
        puts("2. Delete Product");
        puts("3. Exit");
        printf("Choose [1-3] > ");
        scanf("%d",&choices); getchar();
        if(choices == 1)
        {
            system("cls");
            addNewProd();
        }
        if (choices == 2)
        {
            if (totalData == 0)
            {
                system("cls");
                printf("No Product Yet\n");
                getchar();
                main();
            }
            else
            {
                system("cls");
                printTable();
                printf("\n");
                delProd();
                main();
            }
        }
        if (choices == 3)
        {
            system("cls");
            printf("Have a nice day, Goodluck :)\n");
            getchar();
            exit(0);
        }
    } while (choices < 1 || choices > 3);
    puts("");
    main();
}
