//Stack Linked List Implementation
//Tutorial
#include <stdio.h>
#include <stdlib.h>

struct stack {
	int data;
	struct stack *next;
};

void isEmpty(struct stack *top){
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else printf("Stack is not empty\n");
    
}

struct stack *push (struct stack *top, int val){
    struct stack *ptr = (struct stack*) malloc (sizeof(struct stack*));
    ptr->data = val;
    if (top == NULL){
        top = ptr;
        top -> next = NULL;
    } else {
        ptr -> next = top;
        top = ptr;
    }
    printf("%d pushed to stack\n", val);
    return top;
}

struct stack *pop (struct stack *top){
    struct stack *ptr;
    ptr = top;
    if (top == NULL){
        printf("\n STACK UNDERFLOW\n");
    } else {
        top = top->next;
        printf("\nThe deleted value: %d\n", ptr->data);
        free(ptr);
    }
    return top;
}

struct stack *display(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if (top == NULL){
        printf("\n STACK IS EMPTY");
    } else {
        while(ptr != NULL){
            printf("\n%d", ptr -> data);
            ptr = ptr -> next;
        }
        printf("\n");			
    }
    return top;
}

int size(struct stack *top){
    int count = 0;
    struct stack *ptr = top;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int peek(struct stack *top)
{
	return top->data;
}

int main()
{
	struct stack *top = NULL;
    
    isEmpty(top);
    printf("%d \n", size(top));

	top = push(top, 10);
	top = push(top, 20);
	top = push(top, 30);

    printf("%d \n", size(top));

	top = pop(top);
    isEmpty(top);

    printf("%d \n", size(top));

    top = display(top);

	printf("Top element is %d\n", peek(top));

	return 0;
}

// 2540125983 - Brian Giovanni Haryadi
// Terminal Output

// Stack is empty    
// 0 
// 10 pushed to stack
// 20 pushed to stack
// 30 pushed to stack
// 3

// The deleted value: 30
// Stack is not empty
// 2

// 20
// 10
// Top element is 20