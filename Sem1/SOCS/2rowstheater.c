#include <stdio.h>

int main()
{
    int tc;
	scanf("%d", &tc);
	getchar();
	for(int i=1; i<=tc; i++)
    {
		int a;
		scanf("%d", &a);
		getchar();
		int arr[a];
		int jum[505];
        int temp = 0;
		for(int j=0; j<505; j++)
        {
			jum[j] = 0;
		}
		for(int j=0; j<a; j++)
        {
			scanf("%d", &arr[j]);
			getchar();
		}
		for(int j=0; j<a; j++)
        {
			for(int k=0; k<a-1-j; k++)
            {
				if(arr[k] > arr[k+1])
                {
					temp = arr[k];
					arr[k] = arr[k+1];
					arr[k+1] = temp;
				}
			}
		}
		int index = 0;
		for(int j=0; j<a/2-1; j++)
        {
			if(arr[j] != arr[j+1])
            {
				jum[index] = arr[j+1] - arr[j];
				++index;
			}
		}
		for(int j=a/2; j<a-1; j++)
        {
			if(arr[j] != arr[j+1])
            {
				jum[index] = arr[j+1] - arr[j];
				++index;
			}
		}
		int max = 0;
		for(int j=0; j<index; j++)
        {
			if(jum[j] > max)
            {
				max = jum[j];
			}
		}
		printf("Case #%d: %d\n", i, max);
	}
    return 0;
}