#include <stdio.h>

int main()
{
	int c;
	char karakter[1005];
	int i,j;
	scanf("%d",&c);
	for(i = 0;i < c;i++)
    {
		int len = 0;
		scanf("%s",&karakter); getchar();
		for(j = 0; karakter[j] != '\0';j++)
		{
			len++;
		}
		printf("Case %d: ", i + 1);
        for(j = len-1; j >= 0; j--)
        {
            if(j > 0)
			{
				printf("%d",karakter[j] % 2);
			}
			else if(j == 0)
			{
				printf("%d\n",karakter[j] % 2);
			}
        }
	}			
	return 0;
}