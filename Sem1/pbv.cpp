#include <stdio.h>

// main function sebagai function yang dijalankan
// void / int sebelum nama function adalah return type
// int adalah integer
int main(){
	// /n untuk enter
	char huruf = 'a';
	char huruf2 = 'b';
	char huruf3 = 'c';
	char nama[20];

	printf("nama saya : ");
	scanf("%s",&nama);
	
// character = 1 karakter
// string = kumpulan karakter
	float umur;
	printf("kamu umur berapa? \n");
	scanf("%f", &umur);
//array selalu dimulai dari 0

	float goblok;
	printf("apakah kamu goblok? \n");
	scanf("%f", &goblok);
	
	printf("status saya : %f \n",goblok);
	printf("huruf keempat nama saya adalah %c \n",nama[0]);
	printf("nama saya %s \n",nama);
	printf("umurku %d \n",umur);
	
	return 0;
}
 
