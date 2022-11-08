#include <stdio.h>
int main(){
	int a,i,j;
	scanf("%d", &a); getchar();
	for (i = 0; i < a;i++)
    {
		int uk;
		scanf("%d", &uk);
		long long int arr1[uk][uk];
		long long int jum[10000] = {};
		for (j = 0;j < uk;j++)
        {
			for (int k = 0; k < uk;k++)
            {
				scanf("%lld", &arr1[j][k]);
				jum[k] += arr1[j][k];
			}
		}
		printf("Case #%d: ",i+1);
		for (int k = 0;k < uk;k++)
        {
			printf("%lld", jum[k]);
			if (k < uk-1)
            {
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
	}
    return 0;
}

