#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
  char rank;
  char username[255];
  long long int point;
  int height, bf;
  Node *left, *right;
};

Node *root = NULL;

Node *createNewData(const char rank, const char username[], long long int point)
{
  Node *newData = (Node *)malloc(sizeof(Node));
  newData->rank = rank;
  strcpy(newData->username, username);
  newData->point = point;
  newData->bf = 0;
  newData->left = NULL;
  newData->right = NULL;
  return newData;
}

int countA = 0;
int countB = 0;
int countC = 0;
int countD = 0;
int countE = 0;
int countF = 0;

int max(int left, int right)
{
  if(left > right) return left;
  else return right;
}

int height(Node *curr)
{
  if(curr == NULL) return 0;
  return curr->height;
}

int getBf(Node *curr)
{
  if(curr == NULL) return 0;
  else return height(curr->left) - height(curr->right);
}

Node *updateBF(Node *curr)
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
  curr = updateBF(curr);
  x = updateBF(x);
  return x;
}

Node *rightRotate(Node *curr)
{
  Node *x = curr->left;
  Node *temp = x->right;
  x->right = curr;
  curr->left = temp;
  curr = updateBF(curr);
  x = updateBF(x);
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

Node *insert(Node *curr, const char rank, const char username[], long long int point)
{
  if (curr == NULL)
  {
    curr = createNewData(rank, username, point);
  }
  else if (strcmp(username, curr->username) < 0)
  {
    curr->left = insert(curr->left, rank, username, point);
  }
  else if (strcmp(username, curr->username) > 0)
  {
    curr->right = insert(curr->right, rank, username, point);
  }
  else return curr;
  return selfBalancing(updateBF(curr));
}

Node *search(Node *curr, const char target[])
{
  if(curr == NULL) return NULL;
  else if (strcmp(target, curr->username) < 0)
  {
    return search(curr->left, target);
  }
  else if (strcmp(target, curr->username) > 0)
  {
    return search(curr->right, target);
  }
  else if (strcmp(target, curr->username) == 0)
  {
    return curr;
  }
}

Node *getPredecessor(Node *curr)
{
    Node *temp = curr->left;
    while (temp->right!=NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *removeNode(Node *curr, char target[])
{
  if(curr == NULL) return curr;
  else if (strcmp(target, curr->username) < 0)
  {
    curr->left = removeNode(curr->left, target);
  }
  else if (strcmp(target, curr->username) > 0)
  {
    curr->right = removeNode(curr->right, target);
  }
  else
  {
    if (curr->left == NULL && curr->right == NULL)
    {
      free(curr);
      curr = NULL;
      return NULL;
    }
    else if (curr->left == NULL || curr->right == NULL)
    {
      Node *temp = curr->right ? curr->right : curr->left;
      curr = temp;
      return curr;
    }
    else if (curr->left != NULL && curr->right != NULL)
    {
      Node *temp = getPredecessor(curr->left);
      strcpy(curr->username, temp->username);
      curr->left = removeNode(curr->left, temp->username);
    }
  }
  return selfBalancing(updateBF(curr));
}

void inOrderViewAll(Node *curr)
{
  if(curr == NULL) return;
  inOrderViewAll(curr->left);
  printf("A(%d):\n-%s %d",countA, curr->username, curr->point);
  printf("B(%d):\n-%s %d",countB, curr->username, curr->point);
  printf("C(%d):\n-%s %d",countC, curr->username, curr->point);
  printf("D(%d):\n-%s %d",countD, curr->username, curr->point);
  printf("E(%d):\n-%s %d",countE, curr->username, curr->point);
  printf("F(%d):\n-%s %d",countF, curr->username, curr->point);
  inOrderViewAll(curr->right);
}

void inOrderViewRank(Node *curr, char target)
{
  if(curr == NULL) return;
  inOrderViewRank(curr->left);
  int currentCount = 0;
  if (target == 'A') currentCount = countA;
  else if(target == 'B') currentCount = countB;
  else if(target == 'C') currentCount = countC;
  else if(target == 'D') currentCount = countD;
  else if(target == 'E') currentCount = countE;
  else currentCount = countF;
  printf("%c(%d):\n-%s %d",target, currentCount, curr->username, curr->point);
  inOrderViewAll(curr->right);
}

void updatePoint(Node *curr, char rank, char username[], int updatedPoint)
{
  curr = search(curr, username);
  if (curr == NULL)
  {
    exit;
  }
  else
  {
    curr->point = updatedPoint;
  }
}

int main()
{
  int count = 0;
  scanf("%d",count); getchar();
  for (int i = 0; i < count; i++)
  {
    char input[255] = {};
    scanf("%[^\n]",&input); getchar();
    int ctr = 0;
    char *p = strtok(input, " ");
    char *strings[10];
    while (p != NULL)
    {
      strings[ctr++] = p;
      p = strtok (NULL, " ");
    }
    if (strcmp(strings[0], "ADD") == 0)
    {
      system("cls");
      printf("Case %d:\n",i);
      if (input[4] == 'A')
      {
        countA += 1;
      }
      else if (input[4] == 'B')
      {
        countB += 1;
      }
      else if (input[4] == 'C')
      {
        countC += 1;
      }
      else if (input[4] == 'D')
      {
        countD += 1;
      }
      else if (input[4] == 'E')
      {
        countE += 1;
      }
      else countF += 1;
      long long int point = atoi(strings[3]);
      root = insert(root, input[4], strings[2], point);
      printf("Successfully Added!\n");
    }
    else if (strcmp(strings[0], "SHOW-ALL") == 0)
    {
      inOrderView(root);
    }
    else if (strcmp(strings[0], "SHOW-RANK") == 0)
    {
      inOrderViewRank(root, strings[1]);
    }
    else if(strcmp(strings[0], "UPDATE-POINT") == 0)
    {
      long long int point = atoi(strings[3]);
      updatePoint(root, input[13], strings[2], point);
    }
  }
  return 0;
}

// mohon maaf pak, untuk casenya saya tidak terlalu bisa, karena ini sangat beda
// dengan uap yang kemarin saya pelajari. jadi saya tidak bisa menjalankan namun 
// ini bekerja dengan baik secara logika.