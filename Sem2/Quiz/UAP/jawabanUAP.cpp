#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct Node {
    char orderID[255];
    char custName[255];
    char custAddress[255];
    char custFlavour[255];
    long long int custCakeSize;
    int height, bf;
    Node *left, *right;
};

Node *root = NULL;

int dataCount = 0;

Node *createnewData(const char id[], const char name[], const char address[], const char flavour[], long long int size)
{
    Node *newData = (Node *)malloc(sizeof(Node));
    strcpy(newData->orderID, id);
    strcpy(newData->custName, name);
    strcpy(newData->custAddress, address);
    strcpy(newData->custFlavour, flavour);
    newData->custCakeSize = size;
    newData->bf = 0;
    newData->left = NULL;
    newData->right = NULL;
    return newData;
}

int max(int left, int right)
{
    if(left > right) return left;
    else return right;
}

int height(Node *curr)
{
    if(curr == NULL) return 0;
    return curr->height;
}

int getBF(Node *curr)
{
    if(curr == NULL) return 0;
    else return height(curr->left) - height(curr->right);
}

Node *updateBalanceFactor(Node *curr)
{
    curr->height = 1 + max(height(curr->left), height(curr->right));
    curr->bf = height(curr->left) - height(curr->right);
    return curr;
}

Node *leftRotate(Node *curr)
{
    Node *x = curr->right;
    Node *temp = x->left;
    x->left = curr;
    curr->right = temp;
    curr = updateBalanceFactor(curr);
    x = updateBalanceFactor(x);
    return x;
}

Node *rightRotate(Node *curr)
{
    Node *x = curr->left;
    Node *temp = x->right;
    x->right = curr;
    curr->left = temp;
    curr = updateBalanceFactor(curr);
    x = updateBalanceFactor(x);
    return x;
}

Node *selfBalance(Node *curr)
{
    if (curr->bf > 1 && curr->left->bf > 0)
    {
        return rightRotate(curr);
    }
    else if (curr->bf > 1 && curr->left->bf < 0)
    {
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }
    else if (curr->bf < -1 && curr->right->bf < 0)
    {
        return leftRotate(curr);
    }
    else if (curr->bf < -1 && curr->right->bf > 0)
    {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }
    return curr;
}

Node *insert(Node *curr, const char id[], const char name[], const char address[], const char flavour[], long long int size)
{
    if (curr == NULL)
    {
        curr = createnewData(id, name, address, flavour, size);
    }
    else if (strcmp(id, curr->orderID) < 0)
    {
        curr->left = insert(curr->left, id, name, address, flavour, size);
    }
    else if (strcmp(id, curr->orderID) > 0)
    {
        curr->right = insert(curr->right, id, name, address, flavour, size);
    }
    else return curr;
    return selfBalance(updateBalanceFactor(curr));
}

char randomID[255];

void *random(char name[])
{
    srand(time(NULL));
    char tempName[255];
    
    for (int i = 0; i < strlen(name); i++)
    {
        tempName[i] = toupper(name[i]);
    }
    int random = rand() % (100 - 0);
    random = random % 100;
    sprintf(randomID,"%c%c%c%d",tempName[0],tempName[1],tempName[2], random);
}

Node *search(Node *curr, const char target[])
{
    if(curr == NULL) return NULL;
    else if (strcmp(target,curr->orderID) < 0)
    {
        return search(curr->left, target);
    }
    else if (strcmp(target,curr->orderID) > 0)
    {
        return search(curr->right, target);
    }
    else if (strcmp(target, curr->orderID) == 0)
    {
        return curr;
    }
}

Node *getPredecessor(Node *curr)
{
    Node *temp = curr->left;
    while (temp->right!=NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *removeNode(Node *curr, char target[])
{
    if(curr == NULL) return curr;
    else if (strcmp(target, curr->orderID) < 0)
    {
        curr->left = removeNode(curr->left, target);
    }
    else if (strcmp(target, curr->orderID) > 0)
    {
        curr->right = removeNode(curr->right, target);
    }
    else
    {
        if (curr->left == NULL && curr->right == NULL)
        {
            free(curr);
            curr = NULL;
            return NULL;
        }
        else if (curr->left == NULL || curr->right == NULL)
        {
            Node *temp = curr->right ? curr->right : curr->left;
            curr = temp;
            return curr;
        }
        else if (curr->left != NULL && curr->right != NULL)
        {
            Node *temp = getPredecessor(curr->left);
            strcpy(curr->orderID, temp->orderID);
            curr->left = removeNode(curr->left, temp->orderID);
        }
    }
    return selfBalance(updateBalanceFactor(curr));
}

Node *removeAll(Node *curr)
{
    while (curr != NULL)
    {
        curr = removeNode(curr, curr->orderID);
    }
    dataCount = 0;
    return curr;
}

void preOrderView(Node *curr)
{
    if(curr == NULL) return;
    printf("%s %s %s %s %lld\n",curr->orderID, curr->custName, curr->custAddress, curr->custFlavour, curr->custCakeSize);
    preOrderView(curr->left);
    preOrderView(curr->right);
}

void inOrderView(Node *curr)
{
    if(curr == NULL) return;
    inOrderView(curr->left);
    printf("%s %s %s %s %lld\n",curr->orderID, curr->custName, curr->custAddress, curr->custFlavour, curr->custCakeSize);
    inOrderView(curr->right);
}

void postOrderView(Node *curr)
{
    if(curr == NULL) return;
    postOrderView(curr->left);
    postOrderView(curr->right);
    printf("%s %s %s %s %lld\n",curr->orderID, curr->custName, curr->custAddress, curr->custFlavour, curr->custCakeSize);
}

int main()
{
    int choices = 0;
    do
    {
        system("cls");
        printf("HoLland Cakery 39\n");
        printf("1. Insert order\n");
        printf("2. View all order\n");
        printf("3. Delete Order\n");
        printf("4. Clear all orders\n");
        printf("5. Exit\n>> "); scanf("%d",&choices);
        if (choices == 1)
        {
            system("cls");
            char tempCustName[255] = {};
            char tempCustAddress[255];
            char tempCustFlavour[255];
            long long int tempCustCakeSize;
            do
            {
                printf("Input customer name [between 5-20 characters]: ");
                scanf("%[^\n]",tempCustName); getchar();
                if (strlen(tempCustName) < 5 || strlen(tempCustName) > 20)
                {
                    printf("\nCustomer name length must be between 5-20 characters!\n");
                }
            } while (strlen(tempCustName) < 5 || strlen(tempCustName) > 20);
            int checkAddress = 0;
            do
            {
                printf("Input address [ends with 'Street']: ");
                scanf("%[^\n]",&tempCustAddress); getchar();
                int len = strlen(tempCustAddress);
                if (tempCustAddress[len-1] == 't' && tempCustAddress[len-2] == 'e' && tempCustAddress[len-3] == 'e' && tempCustAddress[len-4] == 'r' && tempCustAddress[len-5] == 't' && tempCustAddress[len-6] == 'S')
                {
                    checkAddress = 0;
                }
                else 
                {
                    checkAddress = 1;
                    printf("\nAddress must end with 'Street'!\n");
                }
            } while (checkAddress != 0);
            int checkFlavour = 0;
            do
            {
                printf("Input cake flavour [Vanilla | Chocolate]: ");
                scanf("%[^\n]",&tempCustFlavour); getchar();
                if ((strcmp(tempCustFlavour, "Vanilla") == 0) || (strcmp(tempCustFlavour, "Chocolate") == 0))
                {
                    checkFlavour = 0;
                }
                else 
                {
                    checkFlavour = 1;
                    printf("\nFlavour must be either Vanilla or Chocolate!\n");
                }
            } while (checkAddress != 0);
            int checkSize = 0;
            do
            {
                printf("Input cake diameter [16 | 18 | 21]: ");
                scanf("%lld",&tempCustCakeSize); getchar();
                if (tempCustCakeSize == 16 || tempCustCakeSize == 18 || tempCustCakeSize == 21)
                {
                    checkSize = 0;
                }
                else
                {
                    checkSize = 1;
                    printf("\nDiameter must be either 16 / 18 / 21!\n");
                }
            } while (checkSize != 0);
            dataCount++;
            random(tempCustName);
            root = insert(root, randomID, tempCustName, tempCustAddress, tempCustFlavour, tempCustCakeSize);
            printf("Successfully add data!\n"); getchar(); main();
        }
        else if (choices == 2)
        {
            system("cls");
            if (dataCount == 0)
            {
                printf("no cake order\n"); getchar();
                main();
            }
            else
            {
                int inputMenu = 0;
                printf("View Menus\n");
                printf("1. Pre-Order\n");
                printf("2. In-Order\n");
                printf("3. Post Order\n>> ");
                scanf("%d",&inputMenu); getchar();
                if (inputMenu == 1)
                {
                    printf("ID|Name|Address|Flavour|Diameter\n");
                    preOrderView(root);
                    getchar();
                    main();
                }
                else if (inputMenu == 2)
                {
                    printf("ID|Name|Address|Flavour|Diameter\n");
                    inOrderView(root);
                    getchar();
                    main();
                }
                else if (inputMenu == 3)
                {
                    printf("ID|Name|Address|Flavour|Diameter\n");
                    postOrderView(root);
                    getchar();
                    main();
                }
            }
        }
        else if (choices == 3)
        {
            if (dataCount == 0)
            {
                printf("no cake order\n");
                getchar(); main();
            }
            else
            {
                printf("ID|Name|Address|Flavour|Diameter\n");
                inOrderView(root);
                char deleteCakeID[255];
                printf("Input Cake ID: ");
                scanf("%s",&deleteCakeID); getchar();
                root = search(root, deleteCakeID);
                if (root == NULL)
                {
                    printf("\nid not found!\n");
                    getchar(); main();
                }
                else
                {
                    char deleteConfirm[200];
                    int confirmDelete = 0;
                    do
                    {
                        printf("\nare you sure ? [Yes | No]: ");
                        scanf("%s",&deleteConfirm); getchar();
                        if ((strcmp("Yes",deleteConfirm) == 0) || (strcmp("No",deleteConfirm) == 0))
                        {
                            confirmDelete = 0;
                        }
                        else confirmDelete = 1;
                    } while (confirmDelete == 1);
                    root = removeNode(root, deleteCakeID);
                    dataCount--;
                    printf("data successfully removed!\n");
                    getchar(); main();
                }
            }
        }
        else if (choices == 4)
        {
            if (dataCount == 0)
            {
                printf("no cake order\n");
                getchar(); main();
            }
            else
            {
                system("cls");
                root = removeAll(root);
                dataCount = 0;
                printf("All data successfully removed!\n");
            }
        }
        else if (choices == 5)
        {
            exit(0);
        }
    } while (choices < 1 || choices > 5);
}