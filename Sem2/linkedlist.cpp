#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node *next;
}*head, *tail;

Node *createNewNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void pushHead(int data)
{
	if(head == NULL)
	{
		head = tail = createNewNode(data);
	}
    else
    {
        Node *beforeInsert = head;
        head = createNewNode(data);
        head->next = beforeInsert;
    }
}

void pushTail(int data)
{
    if (head == NULL)
    {
        head = tail = createNewNode(data);
    }
    else
    {
        Node *insert = createNewNode(data);
        tail->next = insert;
        tail = insert;
    }
}

void pushMid(int data)
{
    if (head == NULL)
    {
        head = tail = createNewNode(data);
    }
    else if(data < head->data)
    {
        pushHead(data);
    }
    else if (data > tail->data)
    {
        pushTail(data);
    }
    else
    {
        Node *curr = head;
        while (curr->next->data < data)
        {
            curr = curr->next;
        }
        Node *insertNode = createNewNode(data);
        Node *beforeInsert = curr;
        Node *afterInsert = curr->next;
        beforeInsert->next = insertNode;
        insertNode->next = afterInsert;
    }
}

// pertama, kita harus mengecek apakah head dan tail memiliki value atau tidak
// apabila head memiliki value, bandingkan value head dan value yang akan diassign
// apabila value head lebih kecil dari value yang akan di assign, assign value tersebut ke head.
// lalu jika value tail lebih besar dari value yang akan di assign, assign value tersebut ke tail.
// jika ketiga kondisi sudah di penuhi, kita membuat node baru
//  

void popHead()
{
    if (head == NULL) return;
    Node *deletedHead = head;
    head = head->next;
}

void popTail()
{
    if(head == NULL) return;
    Node *deletedTail = tail;
    Node *curr = head;
    while (curr->next != tail)
    {
        curr = curr->next;
    }
    curr->next = NULL;
    free(deletedTail);
}

void popMid(int data)
{
    if (head == NULL) return;
    else if (data == head->data)
    {
        popHead();
    }
    else if (data == tail->data)
    {
        popTail();
    }
    else
    {
        Node *curr = head;
        while (curr != NULL && curr->data != curr->next->data)
        {
            curr = curr->next;
        }
        if (curr != NULL)
        {
            Node *deletedNode = curr->next;
            Node *beforeDelete = curr;
            beforeDelete->next = deletedNode->next;
            free(deletedNode);
        }   
    }
}

void search(int data)
{
    Node *curr = head;
    while (curr != NULL && curr->data != data)
    {
        curr = curr->next;
    }
    
    if(curr != NULL) 
        printf("%d\n",curr->data);
    else 
        printf("ga ketemu\n");
}

void printNodes()
{
    Node *curr = head;
    while (curr != NULL)
    {
        printf("%d->",curr->data);
        curr = curr->next;
    }
    printf("NULL");
}

void peek()
{
    printf("\n\nHead = %d",head->data);
}

int main()
{
    system ("color 0a");
    // int a = 10;
    // int *p = &a;
    // printf("%d",*p);
    pushHead(1);
    pushTail(100);
    pushMid(50);
    pushMid(25);
    printNodes();
    peek();
    return 0;
}
