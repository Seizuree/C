#include <stdio.h>

int main()
{
    int percobaan;
    scanf("%d",&percobaan); getchar();
    for(int i = 0; i < percobaan; i++)
    {
        int nn;
        scanf("%d",&nn);
        int matriks[nn+1][nn+1];
        int sum1[nn+1];
        int sum = 0;
        for(int j = 0; j < nn; j++)
        {
            for(int k = 0; k < nn; k++)
            {
                scanf("%d",&matriks[j][k]); getchar();
            }
        }
        for(int j = 0; j < nn; j++)
        {
            for(int k = 0; k < nn; k++)
            {
                sum = 0;
                sum += matriks[k][j];
            }
            sum1[j] = sum;
        }
        printf("Case #%d: ",i+1);
		for (int j = 0;j < nn; j++)
        {
			printf("%d", sum1[j]);
			if (j != nn-1)
            {
				printf(" ");
			}
		}
        printf("\n");
    }
}