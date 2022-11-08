#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BSTNode{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} *root = NULL;

struct BSTNode* createNode(int X){
    struct BSTNode *newNode = (struct BSTNode*) malloc(sizeof(struct BSTNode));
    newNode->data = X;
    newNode->left = newNode->right = NULL;

    return newNode;
}

struct BSTNode* findNode(struct BSTNode *curr, int X){
    if (curr == NULL)
    {
        return NULL;
    }
    if (curr->data == X)
    {
        return curr;
    }
    if (X < curr->data)
    {
        return findNode(curr->left, X);
    }
    else if (X > curr->data)
    {
        return findNode(curr->right, X);
    }
}

int countHeight(struct BSTNode *curr){
    if (curr == NULL)
    {
        return -1;
    }
    else
    {
        int leftHeight = countHeight(curr->left);
        int rightHeight = countHeight(curr->right);
        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}

void insertNode(struct BSTNode *curr, int X){
    if(root == NULL){
        root = createNode(X);
    } else if(X != curr->data){
        if(X < curr->data && curr->left == NULL){
            struct BSTNode *temp = createNode(X);
            curr->left = temp;
        } else if(X > curr->data && curr->right == NULL){
            struct BSTNode *temp = createNode(X);
            curr->right = temp;
        } else if(X < curr->data) {
            insertNode(curr->left,X);
        } else {
            insertNode(curr->right,X);
        }
    }
}

void deleteNodeRecursively(struct BSTNode *curr, struct BSTNode *parent){
    if(curr->left == NULL && curr->right == NULL){
        if(curr == root){
            free(curr);
            root = NULL;
        } else {
            if(curr->data < parent->data){
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
            free(curr);
        }
    } else if(curr->left == NULL){
        if(curr == root){
            root = curr->right;
        } else if(curr->data > parent->data){
            parent->right = curr->right;
        } else {
            parent->left = curr->right;
        }
        free(curr);
    } else if(curr->right == NULL){
        if(curr == root){
            root = curr->left;
        } else if(curr->data > parent->data){
            parent->right = curr->left;
        } else {
            parent->left = curr->left;
        }
        free(curr);
    } else {
        struct BSTNode *p = curr->left;
        struct BSTNode *pp = curr;

        while(p->right != NULL){
            pp = p;
            p = p->right;
        }

        int data = p->data;
        deleteNodeRecursively(p,pp);
        curr->data = data;
    }
}

void deleteNode(struct BSTNode *root, int X){
    struct BSTNode *curr = root;
    struct BSTNode *parent = NULL;

    while(curr != NULL){
        if(X == curr->data){
            break;
        }
        parent = curr;
        if(X < curr->data){
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if(curr != NULL){
        deleteNodeRecursively(curr, parent);
    }
}

void inorder(struct BSTNode *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
    int menu,data;
    do{
        printf("\nBinary Search Tree\n");
        printf("====================\n");
        printf("1. Print Inorder\n");
        printf("2. Insert element into BST\n");
        printf("3. Delete element from BST\n");
        printf("4. Find element in BST\n");
        printf("0. Exit\n");
        printf("Input Menu: "); scanf("%d", &menu);
        switch(menu){
            case 1:
                if(root == NULL){
                    printf("BST is empty..\n");
                } else {
                    inorder(root);
                }
                puts("");
                break;
            case 2:
                printf("Input element to be inserted: "); scanf("%d", &data);
                insertNode(root, data);
                printf("Input success\n");
                break;
            case 3:
                printf("Input element to be deleted: "); scanf("%d", &data);
                deleteNode(root, data);
                break;
            case 4:
                printf("Input element to be found: "); scanf("%d", &data);
                struct BSTNode *temp = findNode(root, data);
                if(temp == NULL){
                    printf("Element is not found!\n");
                } else {
                    printf("%d is found!\n", temp->data);
                }
                getchar();
                break;
        }
    }while(menu != 0);

    return 0;
}

// 2540125983 - Brian Giovanni Haryadi