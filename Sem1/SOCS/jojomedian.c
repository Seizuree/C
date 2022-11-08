#include <stdio.h>

int main()
{
	int bnyk;
	scanf("%d", &bnyk); getchar();
	
	char kode[bnyk+5][200];
	char nama[bnyk+5][500];
	double harga[bnyk+5];
	
	for(int i = 0; i < bnyk; i++)
    {
	 	scanf("%s",kode[i]); getchar();
		scanf("%[^\n]",&nama[i]); getchar();
    	scanf("%ld", &harga[i]); getchar();
  	}
  	
	int median = bnyk / 2;
	
	for(int i = 0; i < bnyk; i++)
    {
    	if(harga[i] >= harga[median])
        {
    		printf("%s %s\n", kode[i], nama[i]);
		}
	}
	
	return 0;
}
