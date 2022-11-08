#include <stdio.h>
#include <string.h>

int main (){
	printf("Jawablah dengan seksama! \n");
	printf("Tes ini akan menguji otak Anda.\n \n");
	int nama[255];
	printf("Nama saya : \n");
	scanf("%[^\n]",&nama); getchar();
	printf("\n");
	
	
	char response[255];
	printf("Apakah anda sanggup? (Y/N) \n");
	printf("Gunakan huruf kapital! \n");
	scanf("%[^\n]",&response); getchar();

	printf("Nama saya %s \n",nama);
	
	if(strcmp(response, "Y")==0){
		printf("Selamat, Anda sedikit pintar. \n");
	}
	
	else {
	printf("Selamat, Anda bodoh. \n");
	}	
	printf("Tekan enter untuk keluar dari program ini. \n");
	scanf("%[^\n]",&response); getchar();
	return 0;
}
