#include <stdio.h>

int main()
{
    int t;
 	scanf("%d", &t);
 	getchar();
 	for(int b = 1; b <= t; ++b)
    {
  		int cou;
  		scanf("%d", &cou);
  		int counter[200002];
  		for(int i = 0; i < 200002; i++)
        {
  			counter[i] = 0;
		}
  		int arr[cou];
  		int max = 0;
  		for(int i = 0; i < cou; i++)
        {
   			scanf("%d", &arr[i]);
   			getchar();
            if(arr[i] > max)
            {
    			max = arr[i];
   			}
   			counter[arr[i]]++;
  		}
  		int showed = 0;
		int jum = 0;
  		for (int i = 0; i <= max; i++)
        {
   			if(counter[i] >= showed)
            {
    			showed = counter[i];
    			jum = i;
 			}
		}
        printf("Case #%d: %d\n", b, showed);
        for(int i = 0; i <= jum; i++)
        {
            if(counter[i] == showed)
            {
                printf("%d", i);
                if(i < jum)
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
