#include <stdio.h>

int main()
{
    int t,b;
	int tinggi1=0,tinggi2=0;
 	scanf("%d", &t);
 	
 	for(b = 1; b <= t; b++)
    {
  		int bnyk;
  		scanf("%d", &bnyk);
  		int arr[bnyk];
  		for(int i = 0;i < bnyk;i++)
        {
  		    scanf("%d", &arr[i]);
  		}
 		tinggi1 = arr[0];
   		tinggi2 = arr[1];
 
    	if (tinggi1 < tinggi2)
        {
     	   	int temp = tinggi1;
     	   	tinggi1 = tinggi2;
      		tinggi2 = temp;
    	}
 
    	for (int i = 2; i < bnyk; i++)
        {
     	   if (arr[i] > tinggi1)
            {
    	        tinggi2 = tinggi1;
    	        tinggi1 = arr[i];
    	    }
    	    else if (arr[i] > tinggi2 && arr[i] != tinggi1)
            {
    	        tinggi2 = arr[i];
    	    }
    	}
 		printf("Case #%d: %d\n", b, tinggi1+tinggi2);
  		tinggi1=0;
  		tinggi2=0;
 	}
    return 0;
}