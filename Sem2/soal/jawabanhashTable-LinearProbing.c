//Linear Probing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

struct hashNode{
    char name[20];
    int key;
};

struct hashNode *nd[100];

void init(){
    for(int i=0; i<SIZE; i++){
        nd[i] = NULL;
    }
}

//divison
int hashFunction(char name[]){
    int sum=0; //menyimpan nilai total dari nilai ASCII seluruh karakter name
    int len=strlen(name);
    for(int i=0; i<len; i++){
        sum = sum+name[i];
    }
    return sum%SIZE;
}

void pushName(char name[]){
    int hashVal = hashFunction(name);

    struct hashNode *newNode = (struct hashNode*) malloc (sizeof(struct hashNode));
    strcpy(newNode->name,name);
    newNode->key = hashVal;

    if(nd[hashVal]==NULL){
        nd[hashVal] = newNode;
    }else{//collision
        int i = hashVal+1;
        while(i!=hashVal){
            if(nd[i]==NULL){
                nd[i] = newNode;
                nd[i]->key = i;
                return;
            }
            //i=(i+1)%SIZE;
            i++;
            if(i==SIZE){
                i=0;
            }
        }
        printf("Table is full..\n");
    }
}

int searchData(char name[]){
    int hashVal = hashFunction(name);
    if(nd[hashVal]==NULL){
        return -1;
    } else if(strcmp(nd[hashVal]->name,name)==0){
        return hashVal;
    } else {
        int i=hashVal+1;
        while(i!=hashVal){
            if(nd[i]==NULL){
                return -1;
            } else if(strcmp(nd[i]->name,name)==0){
                return i;
            } else {
                i++;
                if(i==SIZE){
                    i=0;
                }
            }
        }
        return -1;
    }
}

void deleteData(char name[]){
    //pastikan datanya ada di dalam table
    //kalau misalnya, datanya ga ada di dalam table, maka print "Data is not found"
    //kalau misalnya ada, free table dengan index tersebut, kemudian table dengan index tersebut di-NULL kan
    int hashing = hashFunction(name);
    
    free(nd[hashing]);
    nd[hashing] = NULL;
}

void printData(){
    for(int i=0; i<SIZE; i++){
        if(nd[i]!=NULL){
            printf("%d | %s\n", nd[i]->key, nd[i]->name);
        }
    }
    puts("");
}

int main()
{
	init();
	int menu, res;
	char name[20];
	do{
		system("cls"); //clear screen
		printf("Hash Table using Linear Probing\n");
		printf("===============================\n\n");
		printData();
		printf("1. Insert data\n");
		printf("2. Search data\n");
		printf("3. Delete data\n");
        printf("4. Exit\n");
		printf("Enter menu: "); scanf("%d", &menu); getchar();
		switch(menu)
		{
			case 1:
				printf("Input name to be inserted: "); gets(name);
				pushName(name);
				printf("The data has been inserted..\n");
				getchar();
				break;
			case 2:
				printf("Input data to be searched: "); gets(name);
				res=searchData(name);
				if(res!=-1)
					printf("Name %s is found at index %d\n", name, res);
				else 
					printf("Name %s is not found!\n", name);
				getchar();
				break;
			case 3:
				printf("Input data to be deleted: "); gets(name);
				deleteData(name);
				getchar();
				break;
		}
		
	}while(menu!=4);
	return 0;
}

// 2540125983 - Brian Giovanni Haryadi