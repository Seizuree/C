#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
const int size = 100;
int totalData = 0;

char tempUUID[100] = {};
struct Node
{
    char type[100];
    char modifier[100];
    int level;
    int cost;
    char id[100];
    Node *next;
};

Node *hash[size];

Node *createNewNode(const char type[], const char modifier[], int level, int cost, const char id[])
{
    Node *newNode = (Node *)malloc(sizeof(Node *));
    strcpy(newNode->modifier, modifier);
    strcpy(newNode->type, type);
    newNode->level = level;
    newNode->cost = cost;
    strcpy(newNode->id, id);
    newNode->next = NULL;
    return newNode;
}

void createUUID(const char type[], const char modifier[], int level, int cost)
{
    int countMelee = 1;
    int countRange = 1;
    int countSpeed = 1;
    int countHacking = 1;
    if (strcmp(type, "Melee") == 0)
    {
        for (int i = countMelee; i < size; i++)
        {
            if (i < 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%03d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countMelee++;
                break;
            }
            if(i < 10)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%02d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countMelee++;
                break;
            }
            if(i == 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countMelee++;
                break;
            }
        }
    }
    else if (strcmp(type, "Range") == 0)
    {
        for (int i = countRange; i < size; i++)
        {
            if (i < 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%03d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countRange++;
                break;
            }
            if(i < 10)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%02d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countRange++;
                break;
            }
            if(i == 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countRange++;
                break;
            }
        }
    }
    else if (strcmp(type, "Speed") == 0)
    {
        for (int i = countSpeed; i < size; i++)
        {
            if (i < 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%03d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countSpeed++;
                break;
            }
            if(i < 10)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%02d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countSpeed++;
                break;
            }
            if(i == 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countSpeed++;
                break;
            }
        }
    }
    else if (strcmp(type, "Hacking") == 0)
    {
        for (int i = countHacking; i < size; i++)
        {
            if (i < 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%03d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countHacking++;
                break;
            }
            if(i < 10)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%02d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countHacking++;
                break;
            }
            if(i == 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countHacking++;
                break;
            }
        }
    }
}

int hashingKey(const char UUID[])
{
    int sum = 0;
    for (int i = 0; i < strlen(UUID); i++)
    {
        sum += UUID[i];
    }
    sum % 100;
    return sum;
}

Node* insertDataToNode(const char type[], const char modifier[], int level, int cost, const char UUID[])
{
    int key = hashingKey(UUID);
    Node *insert = createNewNode(type, modifier, level, cost, UUID);
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
    return insert;
}

int rng(int level)
{
    int random = rand() % (8 - 5) + 5;
    random = random * level;
    return random;
}

void clearTemp(char target[])
{
    for (int i = 0; i < strlen(target); i++)
    {
        target[i] = '\0';
    }
}

void insertChip()
{
    srand(time(NULL));
    char chipType[100];
    char chipMod[100];
    int chipLevel;
    int verification;
    do
    {
        printf("Chip's type [Attack|System]: ");
        scanf("%s",chipType); getchar();
        for (int i = 0; i < strlen(chipType); i++)
        {
            if ((strcmp(chipType,"Attack") == 0) || strcmp(chipType,"System") == 0)
            {
                verification = 1;
            }
        }
    } while (verification == 0);
    verification = 0;
    do
    {
        printf("Chip's modifier [Melee|Range]: ");
        scanf("%s",chipMod); getchar();
        for (int i = 0; i < strlen(chipMod); i++)
        {
            if (strcmp(chipType, "Attack") == 0)
            {
                if ((strcmp(chipMod, "Melee") == 0) || strcmp(chipMod, "Range") == 0)
                {
                    verification = 1;
                }
            }
            else if(strcmp(chipType, "System") == 0)
            {
                if ((strcmp(chipMod, "Speed") == 0) || strcmp(chipMod, "Hacking") == 0)
                {
                    verification = 1;
                }
            }
        }
    } while (verification == 0);
    do
    {
        printf("Chip's level [must be between 1 and 8]: ");
        scanf("%d",&chipLevel); getchar();
    } while (chipLevel < 0 || chipLevel > 9);
    int chipCost = rng(chipLevel);
    createUUID(chipType, chipMod, chipLevel, chipCost);
    Node *temp = insertDataToNode(chipType, chipMod, chipLevel, chipCost, tempUUID);
    clearTemp(tempUUID);
}

void printHashTable()
{
    for (int i = 0; i < size; i++)
    {
        int counter = 1;
        printf("+================================+\n");
        printf("|%d|%s|%s|%s|%d|%d|\n",counter,hash[i]->id,hash[i]->type,hash[i]->modifier,hash[i]->level,hash[i]->cost);
        printf("+================================+\n");
    }
}

int search(char id[]) 
{
    int key = hashingKey(id);
    Node *temp = hash[key];
    if (strcmp(id, temp->id) == 0)
    {
        return 1;
    }
    else
    {
        while (temp != NULL)
        {
            if (strcmp(temp->id, id) == 0)
            {
                return 1;
            }
            temp = temp->next;
        }
    }
    return 0;
}

void disposeChip()
{
    char chipDelete[100];
    printf("\nInput chip UUID you want to remove: ");
    scanf("%s",chipDelete); getchar();
    int key = hashingKey(chipDelete);
    int found = search(chipDelete);
    if (found == 1)
    {
        if (strcmp(chipDelete, hash[key]->id) == 0)
        {
            Node *temp = hash[key];
            hash[key] = hash[key]->next;
            temp = NULL;
            free(temp);
        }
        else
        {
            Node *temp = hash[key];
            while (strcmp(chipDelete, temp->next->id) == 0 && temp->next != NULL)
            {
                temp = temp->next;
            }
            Node *deleted = temp->next;
            temp->next = deleted->next;
            deleted = NULL;
            free(deleted);
        }
    }
    else
    {
        printf("UUID doesn't exist\n");
        getchar();
    }
}

int main()
{
    int pilihan = 0;
    do
    {
        // system("cls");
        puts("1. Insert Chip");
        puts("2. View Chip");
        puts("3. Dispose Chip");
        puts("0. Exit");
        printf(">> ");
        scanf("%d",&pilihan); getchar();
        if (pilihan == 1)
        {
            insertChip();
            main();
        }
        else if (pilihan == 2)
        {
            if (totalData != 0)
            {
                printHashTable();
                main();
            }
            else main();
        }
        else if(pilihan == 3)
        {
            if(totalData == 0) main();
            else
            {
                printHashTable();
                disposeChip();
                main();
            }
        }
    } while (pilihan < 0 || pilihan > 4);
}