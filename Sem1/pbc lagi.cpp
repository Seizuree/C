#include <stdio.h>

int main (){
	int umur;
	printf("umur saya : ");
	scanf("%d",&umur);
	
	printf("umur saya sekarang : %d \n",umur);
	printf("umur saya kalo dikali 10 : %d \n",umur * 10);
	printf("umur saya kalo dikurang 15 : %d \n",umur - 15);
	printf("umur saya sisanya kalo dibagi 2 : %d \n",umur % 2);
	return 0;
}
