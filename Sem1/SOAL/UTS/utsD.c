#include <stdio.h>

int main()
{
    int input1, input2;
    scanf("%d %d",&input1,&input2);
    for(int a = input1; a <= input2; a++)
    {
  		if(a % 7 == 6)
        {
  			if(a % 5 == 4)
            {
  				if(a % 3 == 2)
                {
  					printf("%d\n", a);
				}
			}
  		}
 	}
	return 0;
}