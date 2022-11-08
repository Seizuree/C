//Queue Linked List Implementation
//Tutorial
#include <stdio.h> 
#include <stdlib.h> 

struct QNode { 
    int value; 
    struct QNode *next; 
}; 

struct Queue { 
    struct QNode *front, *rear; 
}; 

struct Queue *createQueue() 
{ 
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
} 

void push(struct Queue *q, int val) 
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->value = val;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    } 

    q->rear->next = temp;
    q->rear = temp;
} 

void pop(struct Queue *q) 
{
    if (q->front == NULL)
        return;

    struct QNode *temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL) 
        q->rear = NULL;

    free(temp);
} 

void isEmpty(struct Queue *q){
    if(q->front == NULL) printf("Queue is empty\n");
    else printf("Queue is not empty\n");
}

int size(struct Queue *q){
    struct QNode *ptr = q->front;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int main() 
{ 
    struct Queue *q = createQueue();
    push(q, 10);
    push(q, 20);
    pop(q);
    pop(q);
    push(q, 30);
    push(q, 40);
    push(q, 50);
    pop(q);
    push(q, 60);
    printf("Queue Front: %d \n", q->front->value);
    printf("Queue Rear: %d \n", q->rear->value);
    printf("Size: %d \n", size(q));
    isEmpty(q);
    return 0;
} 

// 2540125983 - Brian Giovanni Haryadi
// Terminal Output

// Queue Front: 40
// Queue Rear: 60
// Size: 3
// Queue is not empty