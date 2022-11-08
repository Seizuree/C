#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
    int height;
};

int maxHeight(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int getHeight(struct Node *temp)
{
    if (temp != NULL)
    {
        return temp->height;
    }
    return 0;
}

struct Node *makeNode(int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->value = value;
    temp->height = 1;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *leftRotate(struct Node *temp)
{
    struct Node *pivot = temp->right;
    struct Node *leftChild = pivot->left;
    pivot->left = temp;
    temp->right = leftChild;
    temp->height = maxHeight(getHeight(temp->left),getHeight(temp->right));
    pivot->height = maxHeight(getHeight(pivot->left),getHeight(pivot->right));
    return pivot;
}

struct Node *rightRotate(struct Node *temp)
{
    struct Node *pivot = temp->left;
    struct Node *rightChild = pivot->right;
    pivot->right = temp;
    temp->left = rightChild;
    temp->height = maxHeight(getHeight(temp->left),getHeight(temp->right));
    pivot->height = maxHeight(getHeight(pivot->left),getHeight(pivot->right));
    return pivot;
}

int balanceFactor(struct Node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    return getHeight(temp->left)-getHeight(temp->right);
}

struct Node *insert(struct Node *curr, int value)
{
    if (curr == NULL){
        return makeNode(value);
    }
    if (value < curr->value)
    {
        curr->left = insert(curr->left,value);
    }
    else if (value > curr->value)
    {
        curr->right = insert(curr->right,value);
    }
    curr->height= 1 + maxHeight(getHeight(curr->left),getHeight(curr->right));
    int bf = balanceFactor(curr);
    
    if (bf < -1)
    {
        if (value > curr->right->value)
        {
            return leftRotate(curr);
        }
        else if (value < curr->right->value)
        {
            curr->right=rightRotate(curr->right);
            return leftRotate(curr);
        }
    }
    else if (bf > 1)
    {
        if (value < curr->left->value)
        {
            return rightRotate(curr);
        }
        else if (value > curr->left->value)
        {
            curr->left=leftRotate(curr->left);
            return rightRotate(curr);
        }
    }
    return curr;
}

void inorder(struct Node *curr)
{
    if (curr != NULL)
    {
        inorder(curr->left);
        printf("%d ",curr->value);
        inorder(curr->right);
    }
}

void Postorder(struct Node *curr)
{
    if (curr != NULL)
    {
        Postorder(curr->left);
        Postorder(curr->right);
        printf("%d ",curr->value);
    }
}

void Preorder(struct Node *curr)
{
    if (curr != NULL)
    {
        printf("%d ",curr->value);
        Postorder(curr->left);
        Postorder(curr->right);
    }
}

struct Node *maxValueNode(struct Node *root)
{
    struct Node *curr=root;
    while(curr != NULL && curr->right != NULL)
    {
        curr=curr->right;
    }
    return curr;
}

struct Node *deleteNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        puts("Data Not Found");
        return root;
    }
    if (value < root->value)
    {
        root->left = deleteNode(root->left,value);
    }
    else if (value > root->value)
    {
        root->right = deleteNode(root->right,value);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            puts("Data Found");
            printf("Value %d was deleted\n", value);
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            puts("Data Found");
            printf("Value %d was deleted\n", value);
            free(root);
            return temp;
        }
        struct Node *temp = maxValueNode(root->left);
        root->value = temp->value;
        root->left = deleteNode(root->left,temp->value);
    }
    root->height = 1 + maxHeight(getHeight(root->left),getHeight(root->right));
    int bf = balanceFactor(root);
    if (bf < -1)
    {
        if (balanceFactor(root->right) <= 0)
        {
            return leftRotate(root);
        }
        if (balanceFactor(root->right) > 0)
        {
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }
    }
    else if (bf > 1)
    {
        if (balanceFactor(root->left) >= 0)
        {
            return rightRotate(root);
        }
        if (balanceFactor(root->left) < 0)
        {
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }
    }
    return root;
}

int main()
{
	struct Node *root = NULL;
	int choose = 0;
	do
    {
		system("cls");
		puts("1. Insertion\n2. Deletion\n3. Traversal\n4. Exit");
		printf("Choose : "); 
        scanf("%d", &choose); getchar();
        fflush(stdin);
        if (choose == 1)
        {
            int input = 0;
            printf("Insert : "); 
            scanf("%d", &input); getchar();
            fflush(stdin);
			root = insert(root, input);
        }
        else if (choose == 2)
        {
            int remove = 0;
            printf("Delete : "); 
            scanf("%d", &remove); getchar();
            fflush(stdin);
            root = deleteNode(root, remove);
            getchar();
        }
        else if (choose == 3)
        {
            printf("Preorder : "); 
            Preorder(root);
            puts("");
            printf("Inorder : "); 
            inorder(root);
            puts("");
            printf("Postorder : "); 
            Postorder(root);
            puts("");
            getchar();
        }
	} while(choose != 4);
	puts("Thank You"); getchar();
    return 0;
}