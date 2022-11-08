#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dataCounter = 0;

struct Node
{
    char name[30];
    long long int fee = 0;
    char location[35];
    long long int totalCrew = 0;
    char website[30];
    int height, bf;
    Node *left, *right;
};

Node *createNewData(const char name[], long long int fee, const char location[], long long int totalCrew, const char website[])
{
    Node *newData = (Node *)malloc(sizeof(Node));
    strcpy(newData->name, name);
    newData->fee = fee;
    strcpy(newData->location, location);
    newData->totalCrew = totalCrew;
    strcpy(newData->website, website);
    newData->height = 1;
    newData->bf = 0;
    newData->left = newData->right = NULL;
    return newData;
}

int max(int left, int right)
{
    if (left > right)
    {
        return left;
    }
    else
    {
        return right;
    }
}

int height(Node *curr)
{
    if (curr == NULL)
    {
        return 0;
    }
    return curr->height;
}

int getBalanceFactor(Node *curr)
{
    if (curr == NULL)
    {
        return 0;
    }
    else return height(curr->left) - height(curr->right);
}

Node *updateBalanceFactor(Node *curr)
{
    curr->height = 1 + max(height(curr->left), height(curr->right));
    curr->bf = height(curr->left) - height(curr->right);
    return curr;
}

Node *leftRotation(Node *curr)
{
    Node *x = curr->right;
    Node *temp = x->left;
    x->left = curr;
    curr->right = temp;
    curr = updateBalanceFactor(curr);
    x = updateBalanceFactor(x);
    return x;
}

Node *rightRotation(Node *curr)
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
        return rightRotation(curr);
    }
    else if (curr->bf > 1 && curr->left->bf < 0)
    {
        curr->left = leftRotation(curr->left);
        return rightRotation(curr);
    }
    else if (curr->bf < - 1 && curr->right->bf < 0)
    {
        return leftRotation(curr);
    }
    else if (curr->bf < - 1 && curr->right->bf > 0)
    {
        curr->right = rightRotation(curr->right);
        return leftRotation(curr);
    }
    return curr;
}

Node *insert(Node *curr, const char name[], long long int fee, const char location[], long long int totalCrew, const char website[])
{
    if (curr == NULL)
    {
        curr = createNewData(name, fee, location, totalCrew, website);
    }
    else if (strcmp(name, curr->name) < 0)
    {
        curr->left = insert(curr->left, name, fee, location, totalCrew, website);
    }
    else if (strcmp(name, curr->name) > 0)
    {
        curr->right = insert(curr->right, name, fee, location, totalCrew, website);
    }
    else return curr;
    dataCounter++;
    return selfBalancing(updateBalanceFactor(curr));
}

void preOrderView(Node *curr)
{
    if (curr == NULL)
    {
        return;
    }
    printf("%s %lld %s %lld %s\n",curr->name, curr->fee, curr->location, curr->totalCrew, curr->website);
    preOrderView(curr->left);
    preOrderView(curr->right);
}

void inOrderView(Node *curr)
{
    if (curr == NULL)
    {
        return;
    }
    inOrderView(curr->left);
    printf("%s %lld %s %lld %s\n",curr->name, curr->fee, curr->location, curr->totalCrew, curr->website);
    inOrderView(curr->right);
}

void postOrderView(Node *curr)
{
    if (curr == NULL)
    {
        return;
    }
    postOrderView(curr->left);
    postOrderView(curr->right);
    printf("%s %lld %s %lld %s\n",curr->name, curr->fee, curr->location, curr->totalCrew, curr->website);
}

Node *search(Node *curr, const char name[])
{
    if (curr == NULL)
    {
        return NULL;
    }
    else if (strcmp(name, curr->name) < 0)
    {
        return search(curr->left, name);
    }
    else if (strcmp(name, curr->name) > 0)
    {
        return search(curr->right, name);
    }
    else if (strcmp(name, curr->name) == 0)
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
    if (curr == NULL)
    {
        return curr;
    }
    else if (strcmp(name, curr->name) < 0)
    {
        curr->left = removeNode(curr->left, name);
    }
    else if (strcmp(name, curr->name) > 0)
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
        else if(curr->left != NULL && curr->right != NULL)
        {
            Node *temp = getPredecessor(curr->left);
            strcpy(curr->name, temp->name);
            curr->left = removeNode(curr->left, temp->name);
        }
    }
    return selfBalancing(updateBalanceFactor(curr));
}

Node *removeAll(Node *curr)
{
    while (curr != NULL)
    {
        curr = removeNode(curr, curr->name);
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
        puts("+==========================+");
        puts("| WO Wedding Organizer |");
        puts("+==========================+");
        puts("| 1. Add Available Wedding Organizer |");
        puts("| 2. Choose Available Wedding Organizer |");
        puts("| 3. Book All Wedding Organizer |");
        puts("| 4. View Available Wedding Organizer |");
        puts("| 5. Exit |");
        puts("+==========================+");
        printf(">> "); scanf("%d",&choices); getchar();
        if (choices == 1)
        {
            system("cls");
            char tempName[255];
            long long int tempFee = 0;
            char tempLocation[255];
            long long int tempTotalCrew = 0; 
            char tempWebsite[255];
            char confirmInsert;
            do
            {
                printf("Wedding Organizer Name [3 - 25 characters]: ");
                scanf("%[^\n]",&tempName); getchar();
            } while (strlen(tempName) < 3 || strlen(tempName) > 25);
            do
            {
                printf("Wedding Organizer Fee [1,000,000 - 50,000,000]: ");
                scanf("%lld",&tempFee); getchar();
            } while (tempFee < 1000000 || tempFee > 50000000);
            do
            {
                printf("Wedding Organizer Location [4 - 30 characters]: ");
                scanf("%[^\n]",&tempLocation); getchar();
            } while (strlen(tempLocation) < 4 || strlen(tempLocation) > 30);
            do
            {
                printf("Wedding Organizer Total Crew [2 - 2,000]: ");
                scanf("%lld",&tempTotalCrew); getchar();
            } while (tempTotalCrew < 2 || tempTotalCrew > 2000);
            int websiteCheck = 0;
            do
            {
                printf("Wedding Organizer Website [13 - 25 characters]: ");
                scanf("%[^\n]",tempWebsite); getchar();
                int len = strlen(tempWebsite);
                if (tempWebsite[0] == 'w' && tempWebsite[1] == 'w' && tempWebsite[2] == 'w' && tempWebsite[3] == '.')
                {
                    websiteCheck = 0;
                }
                else if (tempWebsite[len-1] == 'd' && tempWebsite[len-2] == 'i' && tempWebsite[len-3] == '.' && tempWebsite[len-4] == 'o' && tempWebsite[len-5] == 'w' && tempWebsite[len-6] == '.')
                {
                    websiteCheck = 0;
                }
                else websiteCheck = 1;
                for (int i = 0; i < len; i++)
                {
                    if (tempWebsite[i] == ' ')
                    {
                        websiteCheck = 1;
                    }
                }
            } while (strlen(tempWebsite) < 13 || strlen(tempWebsite) > 25 || websiteCheck == 1);
            do
            {
                printf("Confirm Insert [y / n] : ");
                scanf("%c",&confirmInsert); getchar();
            } while (confirmInsert != 'y' && confirmInsert != 'n');
            root = insert(root, tempName, tempFee, tempLocation, tempTotalCrew, tempWebsite);
            printf("\nInsert success!\n"); getchar();
            main();
        }
        else if(choices == 2)
        {
            system("cls");
            if (dataCounter == 0)
            {
                printf("All Wedding Organizer is fully booked...\n");
                printf("Press Enter to continue..."); getchar();
                main();
            }
            else
            {
                printf("|Wedding Organizer Name |Price |Location |Total Crew |Website |\n");
                inOrderView(root);
                char deleteName[255];
                printf("Which Wedding Organizer that you want to choose [Name]? ");
                scanf("%[^\n]",&deleteName); getchar();
                root = search(root, deleteName);
                if (root == NULL)
                {
                    printf("Wedding Organizer doesn't exists!\n");
                    printf("Press Enter to continue...");
                    getchar();
                    main();
                }
                else
                {
                    printf("Are you sure %s is the one for you \n",deleteName);
                    char confirmDelete;
                    do
                    {
                        printf("Confirm %s [y / n] : ",deleteName);
                        scanf("%c",&confirmDelete); getchar();
                    } while (confirmDelete != 'y' && confirmDelete != 'n');
                    root = removeNode(root, deleteName);
                    dataCounter--;
                    printf("\nReservation for %s success!\n",deleteName);
                    getchar();
                    main();
                }
            }
        }
        else if (choices == 3)
        {
            system("cls");
            if (dataCounter == 0)
            {
                printf("All Wedding Organizer is fully booked...\n");
                printf("Press Enter to continue..."); getchar();
                main();
            }
            else
            {
                printf("Are you going to book us all?? YAYYY!!\n");
                char confirmBookAll;
                do
                {
                    printf("Confirm Book All [y / n] : ");
                    scanf("%s",&confirmBookAll); getchar();
                } while (confirmBookAll != 'y' && confirmBookAll != 'n');
                root = removeAll(root);
                printf("Reservation for all wedding organizer succeed!");
                getchar();
                main();
            }
        }
        else if (choices == 4)
        {
            system("cls");
            if (dataCounter == 0)
            {
                printf("All Wedding Organizer is fully booked...\n");
                printf("Press Enter to continue..."); getchar();
                main();
            }
            else
            {
                int printChoice = 0;
                do
                {
                    printf("In which way do you want to look at the data?\n");
                    printf("1. PreOrder\n2. InOrder\n3. PostOrder\n>> ");
                    scanf("%d",&printChoice); getchar();
                } while (printChoice < 1 || printChoice > 4);
                printf("|Wedding Organizer Name |Price |Location |Total Crew |Website |\n");
                if (printChoice == 1)
                {
                    preOrderView(root);
                    printf("Press Enter to continue...\n"); getchar();
                    main();
                }
                else if (printChoice == 2)
                {
                    inOrderView(root);
                    printf("Press Enter to continue...\n"); getchar();
                    main();
                }
                else if (printChoice == 3)
                {
                    postOrderView(root);
                    printf("Press Enter to continue...\n"); getchar();
                    main();
                }
            }
        }
    } while (choices < 1 || choices > 4);
    return 0; 
}