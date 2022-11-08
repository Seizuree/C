#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char nama[255];
    int umur;
};

const int size = 10;
Node *hash[size];
int currentSize = 0;

Node *createNewNode(const char nama[], int umur)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->nama, nama);
    newNode->umur = umur;
    return newNode;
}

int hashing(int umur)
{
    int hash = umur % size;
    return hash;
}

void insertNode(const char nama[], int umur)
{
    int key = hashing(umur);
    Node *insert = createNewNode(nama, umur);
    
    if(currentSize == size)
    {
        printf("Table is full\n");
        return;
    }
    if (hash[key] == NULL)
    {
        hash[key] = insert;
        currentSize++;
        return;
    }
    else
    {
        Node *checkpoint = hash[key];
        do
        {
            if (hash[key] == NULL)
            {
                hash[key] = insert;
                currentSize++;
                return;
            }
            key += 1;
            key %= size;
        } while (hash[key] != checkpoint);
    }
}

void pop(int umur)
{
    int key = hashing(umur);
    Node *curr = hash[key];
    if (hash[key]->umur == umur)
    {
        free(hash[key]);
        currentSize--;
        return;
    }
    else
    {
        do
        {
            if (hash[key] != NULL && hash[key]->umur == umur)
            {
                free(hash[key]);
                currentSize--;
                return;
            }
            key += 1;
            key %= size;
        } while (hash[key]!= curr);
        printf("%d was not found on table\n",umur);
    }
}

void printHashTable()
{
    for (int i = 0; i < size; i++)
    {
        printf("Key[%d] : ",i);
        if (hash[i] == NULL)
        {
            printf("NULL\n");
        }
        else 
            printf("%s & %d\n", hash[i]->nama, hash[i]->umur);
    }
}

void search(int umur)
{
    int key = hashing(umur);
    Node *curr = hash[key];
    do
    {
        if (hash[key] != NULL && hash[key]->umur == umur)
        {
            printf("%d & %s was found on table\n",curr->umur,curr->nama);
        }
        
    } while (hash[key] != curr);
    printf("%d was not found on table\n",curr->umur);
}

int main()
{
    insertNode("Brian", 19);
    insertNode("Alex", 20);
    insertNode("Saya",29);
    pop(30);
    search(1);
    printHashTable();
    return 0;
}
