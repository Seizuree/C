#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    char studentNumber[10];
    char studentName[255];
    long long int studentScore;
    char studentEmail[255];
    Node *left, *right;
    int height, bf;
};

Node *createNewNode(const char studentNumber[], const char studentName[], long long int studentScore, const char studentEmail[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->studentNumber, studentNumber);
    strcpy(newNode->studentName, studentName);
    newNode->studentScore = studentScore;
    strcpy(newNode->studentEmail, studentEmail);
    newNode->height = 1;
    newNode->bf = 0;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int max(int left, int right)
{
    if (left > right)
    {
        return left;
    }
    else
    {
        return right;
    }
}

int height(Node *curr)
{
    if (curr == NULL)
    {
        return 0;
    }
    return curr->height;
}

int getBalanceFactor(Node *curr)
{
    if (curr == NULL)
    {
        return 0;
    }
    else return height(curr->left) - height(curr->right);
}

Node *updateBalanceFactor(Node *curr)
{
    curr->height = 1 + max(height(curr->left), height(curr->right));
    curr->bf = height(curr->left) - height(curr->right);
    return curr;
}

Node *leftRotate(Node *curr)
{
    Node *x = curr->right;
    Node *temp = x->left;
    x->left = curr;
    curr->right = temp;
    x = updateBalanceFactor(x);
    curr = updateBalanceFactor(curr);
    return x;
}

Node *rightRotate(Node *curr)
{
    Node *x = curr->left;
    Node *temp = x->right;
    x->right = curr;
    curr->left = temp;
    x = updateBalanceFactor(x);
    curr = updateBalanceFactor(curr);
    return x;
}

Node *selfBalancing(Node *curr)
{
    if (curr->bf > 1 && curr->left->bf > 0)
    {
        return rightRotate(curr);
    }
    else if (curr->bf > 1 && curr->left->bf < 0)
    {
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }
    else if (curr->bf < -1 && curr->right->bf < 0)
    {
        return leftRotate(curr);
    }
    else if (curr->bf < -1 && curr->right->bf > 0)
    {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }
    return curr;
}

Node *insert (Node *curr, const char studentNumber[], const char studentName[], long long int studentScore, const char studentEmail[])
{
    if (curr == NULL)
    {
        curr = createNewNode(studentNumber, studentName, studentScore, studentEmail);
    }
    else if (strcmp(studentNumber, curr->studentNumber) < 0)
    {
        curr->left = insert(curr->left, studentNumber, studentName, studentScore, studentEmail);
    }
    else if (strcmp(studentNumber, curr->studentNumber) > 0)
    {
        curr->right = insert(curr->right, studentNumber, studentName, studentScore, studentEmail);
    }
    else return curr;
    return selfBalancing(updateBalanceFactor(curr));
}

Node *search(Node *curr, const char studentNumber[])
{
    if (curr == NULL)
    {
        return NULL;
    }
    else if (strcmp(studentNumber, curr->studentNumber) < 0)
    {
        return search(curr->left, studentNumber);
    }
    else if (strcmp(studentNumber, curr->studentNumber) > 0)
    {
        return search(curr->right, studentNumber);
    }
    return curr;
}

Node *getPredecessor(Node *curr)
{
    Node *temp = curr->left;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *removeNode(Node *curr, char studentNumber[])
{
    if (curr == NULL)
    {
        return curr;
    }
    else if (strcmp(studentNumber, curr->studentNumber))
    {
        
    }
}

Node *root = NULL;

int main()
{
    int choices = 0;
    system("cls");
    do
    {
        printf("BJ School\n");
        printf("1. Add Student\n2. Delete Student\n3. View All Students\n4. Exit\n");
        printf(">> "); scanf("%d",&choices); getchar();
        if (choices == 1)
        {
            system("cls");
            char tempStudentNumber[10];
            char tempStudentName[255];
            long long int tempStudentScore;
            char tempStudentEmail[255];
            printf("Add Student\n==========\n");
            int studentNumberCheck = 0;
            do
            {
                printf("Input Student No. (length must be 5 characters AND must start with 'BJ' AND UNIQUE): ");
                scanf("%[^\n]",&tempStudentNumber); getchar();
                if (strlen(tempStudentNumber) == 5)
                {
                    studentNumberCheck = 0;
                }
                else studentNumberCheck = 1;
                if (tempStudentNumber[0] == 'B' && tempStudentNumber[1] == 'J')
                {
                    studentNumberCheck = 0;
                }
                else studentNumberCheck = 1;
            } while (studentNumberCheck == 0);
            int studentNameCheck = 0;
            do
            {
                printf("Input Student Name (must be 2 words AND length must be between 5 - 20 characters): ");
                scanf("%[^\n]",&tempStudentName); getchar();
                if (strlen(tempStudentName) < 5 || strlen(tempStudentName) > 20)
                {
                    studentNameCheck = 1;
                }
                else studentNameCheck = 0;
                for (int i = 0; i < strlen(tempStudentName); i++)
                {
                    if (tempStudentName[i] = ' ')
                    {
                        studentNameCheck++;
                    }
                }
            } while (studentNameCheck == 0);
        }
    } while (choices < 1 || choices > 4);
    
    return 0;
}