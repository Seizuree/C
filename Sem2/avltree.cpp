#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *left, *right;
    int height;
};

Node *createNewNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findMax(int left, int right)
{
    if (left > right)
        return left;
    else
        return right;
}

int findHeight(Node *curr)
{
    if (curr == NULL)
        return 0;
    return curr->height;
}

int getBalance(Node *curr)
{
    if(curr == NULL)
        return 0;
    else
        return findHeight(curr->left) - findHeight(curr->right);
}

Node *rightRotate(Node *curr)
{
    Node *x = curr->left;
    Node *temp = x->right;

    x->right = curr;
    curr->left = temp;

    x->height = 1 + findMax(findHeight(x->left), findHeight(x->right));
    curr->height = 1 + findMax(findHeight(curr->left), findHeight(curr->right));

    return x;
}

Node *leftRotate(Node *curr)
{
    Node *x = curr->right;
    Node *temp = x->left;
    // 
    x->left = curr;
    curr->right = temp;
    // 
    x->height = 1 + findMax(findHeight(x->left), findHeight(x->right));
    curr->height = 1 + findMax(findHeight(curr->left), findHeight(curr->right));
    // 
    return x;
}

Node *selfBalance(Node *curr)
{
    curr->height = 1 + findMax(findHeight(curr->left), findHeight(curr->right));
    int bal = getBalance(curr);
    // left left case
    if(bal > 1 && getBalance(curr->left) >= 0)
        return rightRotate(curr);
    // left right case
    if(bal > 1 && getBalance(curr->left) <= 0)
    {
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }
    // right right case
    if (bal < -1 && getBalance(curr->right) <= 0) 
        return leftRotate(curr);
    // right left case
    if (bal < -1 && getBalance(curr->right) > 0)
    {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }
    return curr;
}

void preorder(Node *curr)
{
    if(curr == NULL)
        return;
    printf("%d - %d\n", curr->value, curr->height);
    preorder(curr->left);
    preorder(curr->right);
}

Node* insert(Node *curr, int value)
{
    if (curr == NULL)
        curr = createNewNode(value);
    else if (value < curr->value)
        curr->left = insert(curr->left, value);
    else if (value > curr->value)
        curr->right = insert(curr->right, value);
    else 
        return curr;
    
    return selfBalance(curr);
}

Node *search(Node *curr, int value)
{
    if (curr == NULL)
        return NULL;
    else if (value < curr->value)
        return search(curr->left, value);
    else if (value > curr->value)
        return search(curr->right, value);
    
    return curr;
}

// right most child of left subtree
Node *getPredecessor(Node *curr)
{
    Node *temp = curr->left;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *getSuccessor(Node *curr)
{
    Node *temp = curr->right;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *removeNode(Node *curr, int value)
{
    if (curr == NULL)
    {
        printf("%d not found",curr->value);
        return curr;
    }
    else if (value < curr->value)
    {
        curr->left = removeNode(curr->left, value);
    }
    else if (value > curr->value)
    {
        curr->right = removeNode(curr->right, value);
    }
    else
    {
        // 0 child
        if(curr->left == NULL && curr->right == NULL)
        {
            free(curr);
            curr = NULL;
            return NULL;
        }
        // 1 child
        else if (curr->left == NULL || curr->right == NULL)
        {
            Node *temp;
            if (curr->left == NULL)
                temp = curr->right;
            else
                temp = curr->left;
            
            free(curr);
            curr = NULL;
            return selfBalance(temp);
        }
        // 2 child
        else
        {
            Node *temp = getPredecessor(curr);
            curr->value = temp->value;
            curr->left = removeNode(curr->left,temp->value);
            return selfBalance(curr);
        }
    }
    return selfBalance(curr);
}

Node *removeAll(Node *root)
{
    while(root != NULL)
    {
        root = removeNode(root, root->value);
    }
    return root;
}

Node *updateNode(Node *curr, int value, int newValue)
{
    Node *update = search(curr, value);
    if (update)
    {
        update->value = newValue;
    }
    else
    {
        printf("%d not found\n", value);
    }
    return update;
}

int main()
{
    // Node *root = NULL;
    // root = insert(root, 50);
    // root = insert(root, 25);
    // root = insert(root, 100);
    // root = insert(root, 125);
    // root = insert(root, 150);
    // preorder(root);
    // Node *find = search(root,200);
    // if (find != NULL)
    // {
    //     printf("Found\n");
    // }
    // else printf("Not found\n");
    // updateNode(root, 25, 28);
    // printf("After Update\n");
    // preorder(root);
    Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 16);
    root = insert(root, 17);
    root = insert(root, 18);
    preorder(root);
    printf("======\n");
    root = removeNode(root, 18);
    preorder(root);
    printf("======\n");
    root = removeNode(root, 15);
    preorder(root);
    printf("======\n");
    root = removeNode(root, 14);
    preorder(root);
    printf("======\n");
    root = insert(root,11);
    root = insert(root,13);
    root = insert(root,14);
    root = insert(root,12);
    root = insert(root,8);
    preorder(root);
    printf("======\n");
    root = removeNode(root, 13);
    // preorder(root);
    // printf("======\n");
    // root = updateNode(root, 10, 6);
    preorder(root);
}