#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person
{
    int id;
    char name[255];
    Person *left, *right;
};

Person *createPerson(int id, const char name[])
{
    Person *newP = (Person *)malloc(sizeof(Person));
    newP->id = id;
    strcpy(newP->name, name);
    newP->left = newP->right = NULL;
    return newP;
}

Person *insert(Person *curr, int id, const char name[]) {
    if(curr == NULL) return createPerson(id, name);
    else {
        if (id < curr->id)
            curr->left = insert(curr->left, id, name);
        else if (id > curr->id)
            curr->right = insert(curr->right, id,name);
        return curr;
    }
}

Person *predecessor(Person *curr)
{
    Person *temp = curr;
    while (temp != NULL && temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Person *successor(Person *curr)
{
    Person *temp = curr;
    while (temp != NULL && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Person *pop(Person *curr, int targetID){
    if (curr == NULL)
    {
        return NULL;
    }
    else if (targetID < curr->id)
    {
        curr->left = pop(curr->left, targetID);
    }
    else if (targetID > curr->id)
    {
        curr->right = pop(curr->right, targetID);
    }
    else{
        if (curr->left == NULL && curr->right == NULL)
        {
            free(curr);
            curr = NULL;
            return NULL;
        }
        else if (curr->left == NULL)
        {
            Person *temp = curr;
            curr = curr->right;
            free(temp);
        }
        else if (curr->right == NULL)
        {
            Person *temp = curr;
            curr = curr->left;
            free(temp);
        }
        else
        {
            Person *pre = predecessor(curr->left);
            curr->id = pre->id;
            strcpy(curr->name, pre->name);
            curr->left = pop(curr->left, curr->id);
        }
    }
    return curr;
}

Person *popAll(Person *curr)
{
    if (curr == NULL) return NULL;
    else
    {
        popAll(curr->left);
        popAll(curr->right);
        free(curr);
        curr = NULL;
        return curr;
    }
}

void preorder(Person *curr)
{
    if(curr == NULL) return;
    else
    {
        printf("%d %s -> ",curr->id, curr->name);
        preorder(curr->left);
        preorder(curr->right);
    }
}

void inorder(Person *curr) {
    if(curr == NULL) return;
    else
    {
        inorder(curr->left);
        printf("%d %s -> ",curr->id,curr->name);
        inorder(curr->right);
    }
}

void postorder(Person *curr)
{
    if(curr == NULL) return;
    else
    {
        postorder(curr->left);
        postorder(curr->right);
        printf("%d %s -> ",curr->id, curr->name);
    }
}

Person *search(Person *curr, int targetId)
{
    if(curr == NULL) 
    {
        printf("%d not found!\n",targetId);
        return NULL;
    }
    else {
        if (targetId < curr->id)
            return search(curr->left, targetId);
        else if (targetId > curr->id)
            return search(curr->right, targetId);
        else{
            printf("%d found, name: %s\n", curr->id, curr->name);
            return curr;
        }
    }
}

void update(Person *root, int targetId, const char newName[])
{
    Person *target = search(root, targetId);
    strcpy(target->name, newName);
}


void updateTree(Person *curr, int targetID, int newID, const char name[])
{
    pop(curr, targetID);
    curr = insert(curr, newID, name);
}

int main()
{
    Person *root = NULL;
    root = insert(root, 11, "Risya");
	root = insert(root, 5, "Brian");
	root = insert(root, 15, "Nicholas");
	root = insert(root, 8, "Thariq");
    root = insert(root, 3, "Angela");

    inorder(root);
    puts("\n");
    update(root, 5, "Angga");
    inorder(root);
    printf("\n\nAfter Pop\n\n");
    pop(root, 3);
    inorder(root);
    printf("\nAfter Pop All\n");
    root = popAll(root);
    inorder(root);
    return 0;
}