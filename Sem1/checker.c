#include <stdio.h>

int main(){
    double a, b, c;

    printf("Enter the number of hours : \n");
    scanf("%lf", &a);
    
	printf("Enter the hourly pay rate : \n");
    scanf("%lf", &b);
    
	c = a * b;
    
	printf("The grosspay is = %.lf", c);
    
	return 0;
}

