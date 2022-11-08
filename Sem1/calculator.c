#include <stdio.h>

int main ()
{
	int angka1, angka2;
	char uuuu;
	
	printf("Input numbers right here : \n");
	printf("Don't forget to put operator \n");
	while(1){
		scanf("%d %c %d", &angka1, &uuuu, &angka2);
		
		int hasil;
		
		printf(">> ");
		if(uuuu == '+')
		{ 
		hasil = angka1 + angka2;
		}
		else if (uuuu == '-')
		{
			hasil = angka1 - angka2;
		}
		else if (uuuu == '*'){
			hasil = angka1 * angka2;
		}
		else if (uuuu == '/'){
			hasil = angka1 / angka2;
		}
		printf("Hasil = %d \n", hasil);
	}
	return 0;
}
