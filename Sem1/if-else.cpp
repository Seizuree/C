#include <stdio.h>

int main (){
	printf("Ini akan menguji kebodohan anda. Waspadalah \n");
	char nama[255];
	printf("Nama saya : \n");
	scanf("%[^\n]",&nama); getchar();
	int umur;
	printf("Umur saya : ");
	scanf("%d",&umur);
	printf("Nama anda : %s\n", nama);

	if(umur % 3 == 0){
		printf("Umur anda habis dibagi 3 \n");
		printf("Anda bodoh yah ternyata");
	}
	else if(umur % 3 == 1){
		printf("Umur anda ketika dibagi 3 hasilnya 1 \n");
		printf("Anda cukup bodoh");
	}
	else {
		printf("Umur anda tidak habis dibagi 3 \n");
		printf("Anda sangat bodoh");
	}
	return 0;
}