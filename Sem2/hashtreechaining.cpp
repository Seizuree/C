#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char nama[255];
    int umur;
    Node *next;
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

    if (hash[key] == NULL)
    {
        hash[key] = insert;
        return;
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
}

void printHashTable()
{
    for (int i = 0; i < size; i++)
    {
        printf("Key [%d] : ",i);
        if (hash[i] != NULL)
        {
            printf("%s & %d -> ",hash[i]->nama, hash[i]->umur);
            Node *temp = hash[i];
            if (temp->next != NULL)
            {
                do
                {
                    printf("%s & %d -> ",temp->next->nama,temp->next->umur);
                    temp = temp->next;
                } while (temp->next != NULL);
            }
        }
        printf("NULL \n");
    }
}

void pop(int umur)
{
    int key = hashing(umur);

    if (hash[key]->umur == umur)
    {
        Node *deleted = hash[key];
        hash[key] = hash[key]->next;
        free(deleted);
    }
    else
    {
        Node *temp = hash[key];
        while (temp->next->umur != umur)
        {
            temp = temp->next;
        }
        Node *deleted = temp->next;
        temp->next = deleted->next;
        free(deleted);
    }
}

// int search(int umur)
// {
//     int key = hashing(umur);
//     Node *temp = hash[key];
//     while (temp->next->umur != umur)
//     {
//         temp = temp->next;
//     }
//     return temp->umur;
}

int main()
{
    insertNode("Brian", 19);
    insertNode("Alex", 20);
    insertNode("Saya",29);
    printHashTable();
    puts("");
    pop(19);
    // search(20);
    printHashTable();
    return 0;
}
