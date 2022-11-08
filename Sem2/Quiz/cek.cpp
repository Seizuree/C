#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int size = 100;
int totalData = 0;
struct Node
{
    char type[100];
    char modifier[100];
    int level;
    int cost;
    char UUID[100];
    Node *next;
};

Node *hash[size];
char tempUUID[100];

void createUUID(const char type[], const char modifier[], int level, int cost)
{
    for (int i = totalData+1; i < size; i++)
    {
        if (i < 100)
        {
            sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%03d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
            break;
        }
        if(i < 10)
        {
            sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%02d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
            break;
        }
        if(i == 100)
        {
            sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
            break;
        }
    }
}

Node *createNewNode(const char type[], const char modifier[], int level, int cost, char UUID[])
{
    Node *newNode = (Node *)malloc(sizeof(Node *));
    strcpy(newNode->modifier, modifier);
    strcpy(newNode->type, type);
    newNode->level = level;
    newNode->cost = cost;
    strcpy(newNode->UUID, UUID);
    newNode->next = NULL;
    return newNode;
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

void insertDataToNode(const char type[], const char modifier[], int level, int cost, char UUID[])
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
}

void printHashTable()
{
    int counter = 1;
    Node *temp = hash[0];
    while (temp != NULL)
    {
        printf("|%d|%s|%s|%s|%d|%d|\n",counter,temp->UUID,temp->type,temp->modifier,temp->level,temp->cost);
        temp = temp->next;
    }
    
}

int main()
{
    createUUID("Attack","Brian",10,1);
    printf("%s",tempUUID);
    insertDataToNode("Attack","Melee", 1, 2, tempUUID);
    printHashTable();
}