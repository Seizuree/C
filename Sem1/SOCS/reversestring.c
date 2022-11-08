#include <stdio.h>
#include <string.h>

void sort(char *x, int len)
{
	for (int i = 0;i < len/2; i++)
    {
		char temp = x[i];
		x[i]=x[len-i-1];
		x[len-i-1]=temp;
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
		printf("Case #%d : %s\n", i + 1, x);				
	}			
	return 0;
}