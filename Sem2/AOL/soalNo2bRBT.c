#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data; // data
    int color; // 1 for red, 0 for black
    struct Node* p; // parent pointer
    struct Node* r; // right-child pointer
    struct Node* l; // left child pointer
};

struct Node* root = NULL;

struct Node* bstInsertion(struct Node* trav, struct Node* temp)
{
    if (trav == NULL)
    {
        return temp;
    } 
    if (temp->data < trav->data)
    {
        trav->l = bstInsertion(trav->l, temp);
        trav->l->p = trav;
    }
    else if (temp->data > trav->data)
    {
        trav->r = bstInsertion(trav->r, temp);
        trav->r->p = trav;
    }
    return trav;
}

void rightRotate(struct Node* temp)
{
    struct Node* left = temp->l;
    temp->l = left->r;
    if (temp->l)
    {
        temp->l->p = temp;
    }
    left->p = temp->p;
    if (!temp->p)
    {
        root = left;
    }
    else if (temp == temp->p->l) 
    {
        temp->p->l = left;
    }
    else 
    {
        temp->p->r = left;
    }
    left->r = temp;
    temp->p = left;
}

void leftRotate(struct Node* temp)
{
    struct Node* right = temp->r;
    temp->r = right->l;
    if (temp->r)
    {
        temp->r->p = temp;
    }
    right->p = temp->p;
    if (!temp->p)
    {
        root = right;
    } 
    else if (temp == temp->p->l)
    {
        temp->p->l = right;
    } 
    else 
    {
        temp->p->r = right;
    }
    right->l = temp;
    temp->p = right;
}

void fixup(struct Node* root, struct Node* pt)
{
    struct Node* parent_ptr = NULL;
    struct Node* grand_parent_ptr = NULL;
    while ((pt != root) && (pt->color != 0) && (pt->p->color == 1))
    {
        parent_ptr = pt->p;
        grand_parent_ptr = pt->p->p;
        if (parent_ptr == grand_parent_ptr->l)
        {
            struct Node* uncle_ptr = grand_parent_ptr->r;
            if (uncle_ptr != NULL && uncle_ptr->color == 1)
            {
                grand_parent_ptr->color = 1;
                parent_ptr->color = 0;
                uncle_ptr->color = 0;
                pt = grand_parent_ptr;
            }
            else
            {
                if (pt == parent_ptr->r) 
                {
                    leftRotate(parent_ptr);
                    pt = parent_ptr;
                    parent_ptr = pt->p;
                }
                rightRotate(grand_parent_ptr);
                int t = parent_ptr->color;
                parent_ptr->color = grand_parent_ptr->color;
                grand_parent_ptr->color = t;
                pt = parent_ptr;
            }
        }
        else 
        {
            struct Node* uncle_ptr = grand_parent_ptr->l;
            if ((uncle_ptr != NULL) && (uncle_ptr->color == 1))
            {
                grand_parent_ptr->color = 1;
                parent_ptr->color = 0;
                uncle_ptr->color = 0;
                pt = grand_parent_ptr;
            }
            else 
            {
                if (pt == parent_ptr->l) 
                {
                    rightRotate(parent_ptr);
                    pt = parent_ptr;
                    parent_ptr = pt->p;
                }
                leftRotate(grand_parent_ptr);
                int t = parent_ptr->color;
                parent_ptr->color = grand_parent_ptr->color;
                pt = parent_ptr;
            }
        }
    }
    root->color = 0;
}

void printInorder(struct Node* trav){
    if (trav != NULL)
    {
        printInorder(trav->l);
        printf("%d ", trav->data);
        printInorder(trav->r);
	}
}

int main(){
    int a[10] = {41,22,5,51,48,29,18,21,45,3};
    for (int i = 0; i < 10; i++) 
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->r = NULL;
        temp->l = NULL;
        temp->p = NULL;
        temp->data = a[i];
        temp->color = 1;
        root = bstInsertion(root, temp);
        fixup(root, temp);
    }
    puts("Inorder Traversal of Created Tree");
    printInorder(root);
    return 0;
}