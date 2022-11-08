#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    char huruf;
    int ujung; // 1 berarti ujung, 0 brarti belum
    struct node* edge[128];
}*root = 0;

int penanda = 1;
node* newNode(char p){
    node* temp=(node*)malloc(sizeof(node));
    temp->huruf = p;
    temp->ujung = 0;
    for(int i=0 ; i<128 ; i++) temp->edge[i]=0;
    return temp;
}

void insert(node* curr, char *p){
    if(curr->edge[(int)*p]==0){
        curr->edge[(int)*p] = newNode(*p);
    }
    //kalo sampe ujung
    if(*p=='\0'){
        curr->ujung = 1;
    }
    //kalo belum sampe ujung (masih ada huruf)
    else{
        insert(curr->edge[(int)*p], p+1);
    }
}

char cari[100] = {};
char temp[100] = {};
char input[100] = {};
int counter=0;
char data[200]={};


void printall(node* curr, int ctr){
    for(int i=0; i<128; i++){
      if(curr->edge[i] == NULL){
        counter++;
      }
    }
    if(counter==128){
      printf("Data is empty\n");
    }

    if(curr->ujung==1){
        temp[ctr]=0;
        printf("%s\n", temp);
    }
    for(int i=0 ; i<128 ; i++){
        if(curr->edge[i] != 0){
            temp[ctr]=i;
            printall(curr->edge[i], ctr+1);
        }
    }
}

bool cek_double(node* curr, int ctr){
  if(ctr == (int)strlen(input) && curr->ujung == 1)return true;
  if(curr->edge[(int)input[ctr]]){
    return cek_double(curr->edge[(int)input[ctr]], ctr+1);
  }
  return false;
}

bool cek_double_data(node* curr, int ctr){
  if(ctr == (int)strlen(data) && curr->ujung == 1)return true;
  if(curr->edge[(int)data[ctr]]){
    return cek_double_data(curr->edge[(int)data[ctr]], ctr+1);
  }
  return false;
}

bool cek_double_cari(node* curr, int ctr){
  if(ctr == (int)strlen(cari) && curr->ujung == 1)return true;
  if(curr->edge[(int)cari[ctr]]){
    return cek_double_data(curr->edge[(int)cari[ctr]], ctr+1);
  }
  return false;
}

void find(node* curr, int ctr){
    for(int i=0; i<128; i++){
      if(curr->edge[i] == NULL){
        counter++;
      }
    }
    if(counter==128){
    printf("Data is empty\n");
    }
  //ctr == di huruf berapa
    if(curr->ujung==1 && ctr > (int)strlen(cari)-1){
        //temp[ctr] biar di terakhir print null jadi mentok di a b c
        temp[ctr]='\0';
        if((int)strlen(cari) == ctr){
          printf("Exact Result\n");
          printf("%s\n", temp);
        }
        else{
          if(penanda == 1){
            printf("Suggestion\n");
            penanda= 0;
          }
          printf("%s\n", temp);
        }
    }

    for(int i=0 ; i<128 ; i++){
       if(curr->edge[i] != 0 && ((ctr > (int)strlen(cari)-1) || i==cari[ctr]) ){
           temp[ctr]=i;
           find(curr->edge[i], ctr+1);
       }
    }
}

void deleted(node* curr, int ctr){
  if(ctr == (int)strlen(data) && curr->ujung == 1){
    curr->ujung =0;
    return ;
  }
  deleted(curr->edge[(int)data[ctr]], ctr+1);
}

node* remove(node* root, char data[], int ctr)
{
  if (root == NULL)
  {
    return NULL;
  }
  
}


int main(){
    root = newNode('*');

    int flag = 1;
    int menu;

    do{
      printf("1. Insert data\n");
      printf("2. Delete data\n");
      printf("3. Print all\n");
      printf("4. View suggestion\n");
      printf("5. Exit\n");
      scanf("%d", &menu);
      getchar();

      switch(menu){
        case 1:
        do{
        flag= 0;
        printf("Insert data [must uniqe]: ");
        scanf("%[^\n]", input);
        getchar();

        if(cek_double(root, 0)== true){
          printf("Please insert a uniqe data!\n");
          flag=1;
        }
      }while(flag==1);

        insert(root, input);
        printf("Input success\n");
        break;

        case 2:

        printf("Delete data [must exits]: ");
        scanf("%[^\n]", data);
        getchar();

        if(cek_double_data(root, 0) == true){
          printf("Data succesfully deleted\n");
          // remove(root, data, 0);
          deleted(root, 0);
          printf("deleted\n");
        }
        else{
          printf("Your data not exist\n");
        }
        break;

        case 3:
        printall(root, 0);
        break;

        case 4:
        printf("Input word you want search :");
        scanf("%[^\n]", cari);
        getchar();
        find(root, 0);
        break;
      }
    }while(menu != 5 );
    return 0;
}
