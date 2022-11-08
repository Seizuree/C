#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sort(char *x, int len)
{
	for(int i = 0;i < len/2; i++)
    {
		char temp = x[i];
		x[i]=x[len-i-1];
		x[len-i-1]=temp;
	}	
}

void cekdulu(char *x, int len)
{
	for(int i = 0; i < len; i++)
	{
		if(isupper(x[i]) == 0)
		{
			x[i] = toupper(x[i]);
		}
		else if(islower(x[i]) == 0)
		{
			x[i] = tolower(x[i]);
		}
	}
}

int main(){
	int c;
	scanf("%d", &c);
	for (int i = 0;i < c;i++)
    {
		char x[1000];
		scanf("%s", x);
		int len = strlen(x);
		sort(x, len);
		cekdulu(x, len);
		printf("Case #%d: %s\n", i + 1, x);				
	}			
	return 0;
}