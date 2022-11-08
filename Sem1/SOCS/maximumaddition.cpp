#include <stdio.h>

int main()
{
	int bnyk;
	scanf("%d", &bnyk); getchar();
	for(int i = 0; i < bnyk; i++)
	{
		int x;
		long long int target;
		scanf("%d %lld", &x, &target); 

		int arr[x+2] = {0};
		for(int j = 0; j < x; j++)
		{
			scanf("%d", &arr[j]); getchar();
		}

		long long int sum = 0;
		int count[x+2] = {0};

		for(int j = 0; j < x; j++)
		{
			sum = 0;
			for(int k = j; k < x; k++)
			{
				sum += arr[k];
				if(sum <= target)
				{
					count[j]++;
				}
				else
				{
					break;
				}
			}
		}

		int max = count[0];
		for(int j = 1; j < x; j++)
		{
			if(count[j] > max)
			{
				max = count[j];
			}
		}

		if(max == 0)
		{
			max = -1;
		}

		printf("Case #%d: %d\n", i+1, max);
	}
	return 0;
}
