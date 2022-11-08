#include <stdio.h>
#include <string.h>
#include <Stdlib.h>

// int main()
// {
//     char str[255];
//     system("cls");
//     int res;
//     scanf("%s",str); getchar();
//     for (int i = 0; i < strlen(str); i++)
//     {
//         printf("ASCII = %d\n",str[i]);
//         res += str[i];
//     }
//     printf("Total = %d\n",res);
//     res = res % 9;
//     printf("Res % 9 = %d\n",res);
// }

// #define SIZE 9

// struct hashNode{
//     char name[20];
//     int key;
// };

// int hashFunction(char name[]){
//     int count = 0;
//     for (int i = 0; i < strlen(name); i++)
//     {
//         count += name[i];
//     }
//     return count%SIZE;
// }

// struct node {
//     int key;
//     struct node *left;
//     struct node *right;
// } *root;

// bool search(struct node *curr, int find){
//     if (curr == NULL)
//         return false;
//     if (curr->key == find)
//         return true;
//     if (curr->key > find)
//     {
//         return search(curr->left, find);
//     }
//     if (curr->key < find)
//     {
//         return search(curr->right, find);
//     }
// }

// int heightBinaryTree(struct node *node){
//     if (node == NULL)
//         return -1;
//     else
//     {
//         int tinggiKiri = heightBinaryTree(node->left);
//         int tinggiKanan = heightBinaryTree(node->right);
//         if (tinggiKiri > tinggiKanan)
//             return (tinggiKiri + 1);
//         else
//             return (tinggiKanan + 1);
//     }
// }

char tempUUID[100] = {};

int size = 1;

void createUUID(const char type[], const char modifier[], int level, int cost)
{
    int countMelee = 1;
    int countRange = 1;
    int countSpeed = 1;
    int countHacking = 1;
    if (strcmp(type, "Melee") == 0)
    {
        for (int i = countMelee; i < size; i++)
        {
            if (i < 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%03d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countMelee++;
                break;
            }
            if(i < 10)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%02d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countMelee++;
                break;
            }
            if(i == 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countMelee++;
                break;
            }
        }
    }
    else if (strcmp(type, "Range") == 0)
    {
        for (int i = countRange; i < size; i++)
        {
            if (i < 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%03d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countRange++;
                break;
            }
            if(i < 10)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%02d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countRange++;
                break;
            }
            if(i == 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countRange++;
                break;
            }
        }
    }
    else if (strcmp(type, "Speed") == 0)
    {
        for (int i = countSpeed; i < size; i++)
        {
            if (i < 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%03d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countSpeed++;
                break;
            }
            if(i < 10)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%02d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countSpeed++;
                break;
            }
            if(i == 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countSpeed++;
                break;
            }
        }
    }
    else if (strcmp(type, "Hacking") == 0)
    {
        for (int i = countHacking; i < size; i++)
        {
            if (i < 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%03d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countHacking++;
                break;
            }
            if(i < 10)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%02d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countHacking++;
                break;
            }
            if(i == 100)
            {
                sprintf(tempUUID, "%c%c%c%c%c%c%d%02d%d", type[0], type[1], type[2], modifier[0], modifier[1], modifier[2],level,cost,i);
                countHacking++;
                break;
            }
        }
    }
}

int main()
{
    createUUID("Melee","Attack",2,3);
    printf("%s",tempUUID);
}
