#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dataCount = 0;

struct Node{
    char name[255] = {};
    char priority[255] = {};
    int number = 0;
    Node *next;
}*head;

int prioNumber(const char priority[])
{
    if (strcmp(priority, "VVIP") == 0)
    {
        return 1;
    }
    if (strcmp(priority, "VIP") == 0)
    {
        return 2;
    }
    if (strcmp(priority, "Member") == 0)
    {
        return 3;
    }
    if (strcmp(priority, "Guest") == 0)
    {
        return 4;
    }
    else return 0;
}

Node *createNewNode(const char name[], const char priority[])
{
    Node *temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->name, name);
    strcpy(temp->priority, priority);
    temp->number = prioNumber(priority);
    return temp;
}

void pushData(const char name[], const char priority[])
{
    Node *newData = createNewNode(name,priority);
    Node *curr = head;
    if (head == NULL)
    {
        head = newData;
    }
    else
    {
        int currPrio = prioNumber(priority);
        if (head->number > currPrio)
        {
            newData->next = head;
            head = newData;
        }
        else
        {
            while (curr->next != NULL && curr->next->number < currPrio)
            {
                curr = curr->next;
            }
            newData->next = curr->next;
            curr->next = newData;
        }
        currPrio = 0;
    }
}

void pop()
{
    Node *temp = head;
    head = head->next;
    free(temp);
    dataCount--;
}

void addCust()
{
    char tempName[255] = {};
    char tempPrio[255] = {};
    int validation = 0;
    do
    {
        scanf("%s %s",tempPrio, tempName); getchar();
        if ((strcmp(tempPrio, "VVIP") == 0) || (strcmp(tempPrio, "VIP") == 0) || (strcmp(tempPrio, "Member") == 0) || (strcmp(tempPrio, "Guest") == 0))
        {
            validation = 1;
        }
    } while (validation == 0 || validation < 1);
    pushData(tempName, tempPrio);
    dataCount++;
    strcpy(tempName, "");
    strcpy(tempPrio, "");
}

void serveOne()
{
    Node *temp = head;
    if (strcmp(temp->priority, "VVIP") == 0)
    {
        printf("Attention! %s is being served at VVIP table\n",temp->name);
    }
    if (strcmp(temp->priority, "VIP") == 0)
    {
        printf("Attention! %s is being served at VIP table\n",temp->name);
    }
    if (strcmp(temp->priority, "Member") == 0)
    {
        printf("Attention! Member %s is being served at regular table\n", temp->name);
    }
    if (strcmp(temp->priority, "Guest") == 0)
    {
        printf("Attention! Guest %s is being served at regular table\n",temp->name);
    }
    pop();
}

void serveAll()
{
    Node *temp = head;
    while (temp != NULL)
    {
        serveOne();
    }
}

void dismissQueue()
{
    Node *temp = head;
    while (temp != NULL)
    {
        pop();
        temp = temp->next;
    }
    printf("End of the day\n");
}

void printData()
{
    Node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("%d. %s\n",i,temp->name);
        temp = temp->next;
        i++;
    }
}

int main()
{
    int option = 0;
    do
    {
        system("cls");
        printf("======================\n");
        printf("SUNIB Restaurant Reservation\n");
        printf("======================\n");
        printf("\nWaiting Line:\n");
        if (dataCount == 0)
        {
            printf("Queue is empty\n");
        }
        else
        {
            printData();
        }
        printf("\n");
        printf("1. Add Customer to Queue\n");
        printf("2. Serve One\n");
        printf("3. Serve All\n");
        printf("4. Dismiss Queue\n");
        printf("0. Exit\n");
        printf("Input Menu Number: ");
        scanf("%d",&option); getchar();
        if (option == 1)
        {
            addCust();
            main();
        }
        if (option == 2)
        {
            if (dataCount == 0)
            {
                system("cls");
                printf("No data in queue\n");
                getchar();
                main();
            }
            else
            {
                serveOne();
                getchar();
                main();
            }
        }
        if (option == 3)
        {
            if (dataCount == 0)
            {
                system("cls");
                printf("No data in queue\n");
                getchar();
                main();
            }
            else
            {
                serveAll();
                getchar();
                main();
            }
        }
        if (option == 4)
        {
            dismissQueue();
            getchar();
            main();
        }
        if (option == 0)
        {
            exit(0);
        }
    } while (option < 1 || option > 4);
    return 0;
}
