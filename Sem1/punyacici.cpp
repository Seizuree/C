#include<stdio.h>
#include<string.h>

int main(){
	char str[255];
	printf("Input word [yes|no]: ");
	scanf("%[^\n]", str); getchar();
	
	if(strcmp(str, "yes")==0){
		printf("aku sayang kamu \n");
	}else{
		printf("ini no\n");
	}
}
