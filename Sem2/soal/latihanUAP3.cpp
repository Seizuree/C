#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int dataCounter = 0;

struct Node
{
    char dinoName[30];
    char dinoType[30];
    long long int dinoAge;
    long long int dinoWeight;
    char dinoSkill[30];
    int height, bf;
    Node *left, *right;
};

Node *createNewData(const char name[], const char type[], long long int age, long long int weight, const char skill[])
{
    Node *newData = (Node *)malloc(sizeof(Node));
    strcpy(newData->dinoName, name);
    strcpy(newData->dinoType, type);
    newData->dinoAge = age;
    newData->dinoWeight = weight;
    strcpy(newData->dinoSkill, skill);
    newData->height = 1;
    newData->bf = 0;
    return newData;
}

int max(int left, int right)
{
    if (left > right) return left;
    else return right;
}

int height(Node *curr)
{
    if (curr == NULL) return 0;
    return curr->height;
}

int getBalanceFactor(Node *curr)
{
    if (curr == NULL) return 0;
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

Node *selfBalancing(Node *curr)
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

Node *insert(Node *curr, const char name[], const char type[], long long int age, long long int weight, const char skill[])
{
    if (curr == NULL)
    {
        curr = createNewData(name, type, age, weight, skill);
    }
    else if (age < curr->dinoAge)
    {
        curr->left = insert(curr->left, name, type, age, weight, skill);
    }
    else if (age > curr->dinoAge)
    {
        curr->right = insert(curr->right, name, type, age, weight, skill);
    }
    else return curr;
    dataCounter++;
    return selfBalancing(updateBalanceFactor(curr));
}

void preOrderPrint(Node *curr)
{
    if (curr == NULL) return;
    printf("%s %s %lld %lld %s\n",curr->dinoName, curr->dinoType, curr->dinoAge, curr->dinoWeight, curr->dinoSkill);
    preOrderPrint(curr->left);
    preOrderPrint(curr->right);
}

void inOrderPrint(Node *curr)
{
    if (curr == NULL) return;
    inOrderPrint(curr->left);
    printf("%s %s %lld %lld %s\n",curr->dinoName, curr->dinoType, curr->dinoAge, curr->dinoWeight, curr->dinoSkill);
    inOrderPrint(curr->right);
}

void postOrderPrint(Node *curr)
{
    if (curr == NULL) return;
    postOrderPrint(curr->left);
    postOrderPrint(curr->right);
    printf("%s %s %lld %lld %s\n",curr->dinoName, curr->dinoType, curr->dinoAge, curr->dinoWeight, curr->dinoSkill);
}

Node *search(Node *curr, const char name[])
{
    if (curr == NULL) return NULL;
    else if (strcmp(name, curr->dinoName) < 0)
    {
        return search(curr->left, name);
    }
    else if (strcmp(name, curr->dinoName) > 0)
    {
        return search(curr->right, name);
    }
    else if (strcmp(name, curr->dinoName) == 0)
    {
        return curr;
    }
}

Node *getPredecessor(Node *curr)
{
    Node *temp = curr->left;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *removeNode(Node *curr, char name[])
{
    if (curr == NULL) return curr;
    else if (strcmp(name, curr->dinoName) < 0)
    {
        curr->left = removeNode(curr->left, name);
    }
    else if (strcmp(name, curr->dinoName) > 0)
    {
        curr->right = removeNode(curr->right, name);
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
            strcpy(curr->dinoName, temp->dinoName);
            curr->left = removeNode(curr->left, temp->dinoName);
        }
    }
    return selfBalancing(updateBalanceFactor(curr));
}

Node *removeAll(Node *curr)
{
    while (curr != NULL)
    {
        curr = removeNode(curr, curr->dinoName);
    }
    dataCounter = 0;
    return curr;
}

Node *root = NULL;

int main()
{
    int choices = 0;
    do
    {
        system("cls");
        puts("Jurassic Jungle");
        puts("1. See Dinosaur");
        puts("2. Add Dinosaur");
        puts("3. Remove Dinosaur");
        puts("4. Exit");
        printf(">> "); scanf("%d",&choices); getchar();
        if (choices == 1)
        {
            if (dataCounter == 0)
            {
                printf("There's no dinosaur here!\n");
                printf("Press enter to back..."); getchar();
                main(); 
            }
            else
            {
                system("cls");
                char seeOrder[20];
                int confirmSeeOrder = 0;
                do
                {
                    printf("Choose see order [Pre | In | Post]: ");
                    scanf("%s",&seeOrder); getchar();
                    if ((strcmp("Pre",seeOrder) == 0) || (strcmp("In",seeOrder) == 0) || (strcmp("Post",seeOrder)))
                    {
                        confirmSeeOrder = 1;
                    }
                    else confirmSeeOrder = 0;
                } while (confirmSeeOrder == 0);
                printf("Dinosaur Name | Dinosaur Type | Dinosaur Age | Dinosaur Weight | Dinosaur Skill |\n");
                printf("=================================================================================\n");
                if (strcmp("Pre",seeOrder) == 0)
                {
                    preOrderPrint(root);
                    getchar();
                    main();
                }
                else if (strcmp("In",seeOrder) == 0)
                {
                    inOrderPrint(root);
                    getchar();
                    main();
                }
                else if (strcmp("Post",seeOrder) == 0)
                {
                    postOrderPrint(root);
                    getchar();
                    main();
                }
            }
        }
        else if (choices == 2)
        {
            char tempDinoName[30];
            char tempDinoType[30];
            long long int tempDinoAge;
            long long int tempDinoWeight;
            char tempDinoSkill[30];
            int checkSpace = 0;
            int checkNameInput = 0;
            do
            {
                printf("Input Dinosaur name [10..20 characters]: ");
                scanf("%[^\n]",&tempDinoName); getchar();
                for (int i = 0; i < strlen(tempDinoName); i++)
                {
                    if (tempDinoName[i] == ' ')
                    {
                        checkSpace++;
                    }
                }
                if (tempDinoName[0] == 'S' && tempDinoName[1] == 'u' && tempDinoName[2] == 'p' && tempDinoName[3] == 'e' && tempDinoName[4] == 'r')
                {
                    checkNameInput = 1;
                }
                if (tempDinoName[0] == 'H' && tempDinoName[1] == 'y' && tempDinoName[2] == 'p' && tempDinoName[3] == 'e' && tempDinoName[4] == 'r')
                {
                    checkNameInput = 1;
                }
            } while (strlen(tempDinoName) < 10 || strlen(tempDinoName) > 20 || checkNameInput != 1 || checkSpace < 2);
            int checkType = 0;
            do
            {
                printf("Input Dinosaur type [Carnivore | Herbivore | Omnivore]: ");
                scanf("%[^\n]",&tempDinoType); getchar();
                if ((strcmp("Carnivore",tempDinoType) == 0) && (strcmp("Herbivore",tempDinoType) == 0) && (strcmp("Omnivore",tempDinoType) == 0)) 
                {
                    checkType = 1;
                }
            } while (checkType != 0);
            do
            {
                printf("Input Dino age [must be greater than 1000]: ");
                scanf("%lld",&tempDinoAge); getchar();
            } while (tempDinoAge < 1000);
            do
            {
                printf("Input Dino weight [must be greater than 10000]: ");
                scanf("%lld",&tempDinoWeight); getchar();
            } while (tempDinoWeight < 10000);
            int capitalCheck = 0;
            checkSpace = 0;
            do
            {
                printf("Input Dinosaur skill [One Word, Capital] case sensitive: ");
                scanf("%s",&tempDinoSkill); getchar();
                if (tempDinoSkill[0] == toupper(tempDinoSkill[0]))
                {
                    capitalCheck = 1;
                }
                for (int i = 0; i < strlen(tempDinoSkill); i++)
                {
                    if (tempDinoSkill[i] == ' ')
                    {
                        checkSpace++;
                    }
                }
            } while (checkSpace != 0 || capitalCheck != 1);
            root = insert(root, tempDinoName, tempDinoType, tempDinoAge, tempDinoWeight, tempDinoSkill);
            main();
        }
        else if (choices == 3)
        {
            system("cls");
            if (dataCounter == 0)
            {
                printf("There's no dinosaur here!\n");
                printf("Press enter to back..."); getchar();
                main();
            }
            else
            {
                inOrderPrint(root);
                char searchDino[255];
                printf("\nInput Dino to be find: ");
                scanf("%[^\n]",&searchDino); getchar();
                Node *toSearch = search(root, searchDino);
                printf("%s\n",searchDino);
                printf("%s\n",toSearch->dinoName);
                if (toSearch == NULL)
                {
                    printf("We can't find dino with %s name",searchDino);
                    getchar();
                    main();
                }
                else 
                {
                    root = removeNode(root, searchDino);
                    dataCounter--;
                    printf("\nRemove sucessful");
                    getchar();
                    main();
                }
            }
        }
    } while (choices < 1 || choices > 4);
}