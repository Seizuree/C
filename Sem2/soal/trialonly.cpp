#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30
int userID = 1;

struct Node
{
    char name[100];
    char email[100];
    char phone[100];
    int id;
    Node *next;
};

Node *hash[SIZE];

void init()
{
    for (int i = 0; i < SIZE; i++)
    {
        hash[i] = NULL;
    }
}

Node *createNode(const char name[], const char email[], const char phone[], int id)
{
    Node *newNode = (Node *)malloc(sizeof(Node *));
    strcpy(newNode->email, email);
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

int hashing(const char name[])
{
    int key = 0;
    for (int i = 0; i < strlen(name); i++)
    {
        key += name[i];
    }
    key = key % SIZE;
    return key;
}

void insertData(const char name[], const char email[], const char phone[], int id)
{
    int key = hashing(name);
    Node *insert = createNode(name, email, phone, id);
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
}

void registerNewUser()
{
    char name[100];
    char email[100];
    char phone[100];
    int nameCheck = 0;
    char *result;
    do
    {
        printf("Enter your username [ 1 - 20 char and not with special character ] : ");
        scanf("%[^\n]",name); getchar();
        for (int i = 0; i < strlen(name); i++)
        {
            if ((name[i] >= 'A' && name[i] <= 'a') && (name[i] >= 'a' && name[i] <= 'z'))
            {
                nameCheck = 1;
            }
            if (name[i] >= '0' && name[i] <= '9')
            {
                nameCheck = 0;
            }
        }
    } while (nameCheck == 0 && (strlen(name) < 1 || strlen(name) > 20));
    int emailCheck = 0;
    do
    {
        printf("Enter your email [ ends with '.com' ] : ");
        scanf("%s",email); getchar();
        int len = strlen(email);
        for (int i = 0; i < len; i++)
        {
            if (email[i] == '.' && email[i+1] == 'c' && email[i+2] == 'o' && email[i+3] == 'm')
            {
                emailCheck = 1;
            }
        }
    } while (emailCheck == 0);
    do
    {
        printf("Enter your phone number [ starts with '0' ] : ");
        scanf("%s",phone); getchar();
    } while (phone[0] != '0');
    insertData(name, email, phone, userID);
    userID += 1;
}

void printHashTable()
{
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        Node *curr = hash[i];
        if(curr == NULL) count++;
    }
    if (count == SIZE)
    {
        printf("No account yet!\n");
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node *curr = hash[i];
            while (curr != NULL)
            {
                printf("Tag ID       : %d\n",curr->id);
                printf("Username     : %s\n",curr->name);
                printf("Email        : %s\n",curr->email);
                printf("Phone Number : %s\n\n",curr->phone);
                curr = curr->next;
            }
        }
    }
}

void menu()
{
    int choices = 0;
    do
    {
        // system("cls");
        printHashTable();
        puts("Biscord Gaming!!");
        puts("-------------------");
        puts("1. Register New User");
        puts("2. Delete User");
        puts("3. Exit");
        printf("Choose : ");
        scanf("%d",&choices); getchar();
        if (choices == 1)
        {
            registerNewUser();
            menu();
        }
    } while (choices != 3);
    exit(0);
}

int main()
{
    init();
    menu();
}