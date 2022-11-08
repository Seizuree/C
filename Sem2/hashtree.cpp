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
    
    if (hash[key] == NULL)
    {
        hash[key] = insert;
    }
    else printf("Key %d is already inserted\n",key);
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

int main()
{
    insertNode("Brian", 19);
    insertNode("Alex", 20);
    insertNode("Saya",22);
    printHashTable();
    return 0;
}
