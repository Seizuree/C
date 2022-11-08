#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[255];
    int age;
    Person *next, *prev;
} *head, *tail;

Person *createPerson(const char name[], int age)
{
    Person *newP = (Person *)malloc(sizeof(Person));
    strcpy(newP->name, name);
    newP->age = age;
    newP->next = newP->prev = NULL;
    return newP;
}

void pushHead(const char name[], int age)
{
    Person *newP = createPerson(name, age);
    if (head == NULL)
    {
        head = tail = newP;
    }
    else
    {
        newP->next = head;
        head->prev = newP;
        head = newP;
    }
}

void pushTail(const char name[], int age)
{
    Person *newP = createPerson(name, age);
    if (head == NULL)
    {
        head = tail = newP;
    }
    else
    {
        tail->next = newP;
        newP->prev = tail;
        tail = newP;
    }
}

void pushMid(const char name[], int age)
{
    Person *newP = createPerson(name,age);
    if (head == NULL)
    {
        head = tail = newP;
    }
    else if (head->age < newP->age)
    {
        pushHead(name,age);
    }
    else if (tail->age > newP->age)
    {
        pushTail(name,age);
    }
    else
    {
        Person *curr = head;
        while (curr->age > newP->age)
        {
            curr = curr->next;
        }
        // saat ini kita sudah menemukan node yang lebih kecil agenya drpd newP
        // kita sdh menemukan bob dengan age 20 yg lebih kecil drpd lia 25
        // jadi skrg, curr = bob
        newP->next = curr;
        newP->prev = curr->prev;
        //Bob->prev->next = lia atau John->next = lia
        curr->prev->next = newP;
        //bob->prev = lia
        curr->prev = newP;
    }
}

void popHead()
{
    if(head == NULL) return;
    else if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        Person *newHead = head->next;
        newHead->prev = NULL;
        head->next = NULL;
        free(head);
        head = newHead;
    }
}

void popTail()
{
    if (head == NULL) return;
    else if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        Person *newTail = tail->prev;
        tail->prev = NULL;
        newTail->next = NULL;
        free(tail);
        tail = newTail;
    }
}

void popMid(const char target[])
{
    if(head == NULL) return;
    else if (strcmp(head->name, target) == 0)
    {
        popHead();
    }
    else if (strcmp(tail->name, target) == 0)
    {
        popTail();
    }
    else
    {
        Person *curr = head;
        while (curr != NULL && strcmp(curr->name, target) != 0)
        {
            curr = curr->next;
        }
        if (curr == NULL) return;
        else
        {
            // lia->prev->next = john->next kita isi dengan bob (curr next)
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->next = NULL;
            curr->prev = NULL;
            free(curr);
        }
    }
}

Person *search(const char target[])
{
    Person *curr = head;
    while (curr != NULL)
    {
        if (strcmp(curr->name, target) == 0)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void print()
{
    Person *curr = head;
    while (curr != NULL)
    {
        printf("<- [%s | %d] -> ",curr->name,curr->age);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    pushHead("John",30);
    print();
    pushHead("Jane",50);
    print();
    pushTail("Bob",20);
    print();
    pushMid("Lia",40);
    print();

    Person *lia = search("Lia");
    if (lia != NULL)
    {
        printf("Found %s, age %d\n",lia->name, lia->age);
    }
    else
    {
        printf("Not Found\n");
    }
    popMid("Lia");
    print();
    
    return 0;
}