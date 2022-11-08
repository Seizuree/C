#include<stdio.h>

int main()
{
	int a,b,j;
	scanf("%d",&a);
	for(int ii = 1;ii <= a;ii++)
	{
		scanf("%d",&b);
		printf("Case #%d:\n",ii);
		for(int i = 1;i <= b;i++)
		{
			for(j = i;j < b;j++)
			{
				printf(" ");
			}
			for(j = 1;j <= i;j++)
			{
				if(b%2 == 1)
				{
					if(j%2 == 1)
						printf("*");
					else
						printf("#");
				}
				else
				{
					if(j%2 == 1)
						printf("#");
					else
						printf("*");
				}
			}
		printf("\n");
		} 
	}
	return 0;
}
