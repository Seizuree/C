#include <stdio.h>

void menuOption (int value){
	
	double sidea,side1,width,height;

	if(value==1){
		printf("Input side value : ");
		scanf("%lf",&side1);
		sidea = side1*side1;
		printf("Value of Square area : %.2lf",sidea);		
	}
	else if(value==2){
		printf("Input width value : ");
		scanf("%lf",&width);
		printf("Input height value : ");
		scanf("%lf",&height);
		printf("Value of Rectangle area : %.2lf",width*height);
	}
	else {
		printf("Invalid choices \n");
	}
}

int main (){
	
	int value;
	
	printf("Geometry Area Counter\n" );
 	printf("=====================\n");
	printf("Please choose the option : ");
	scanf("%d",&value);
	menuOption(value);
	
	return 0 ;
}