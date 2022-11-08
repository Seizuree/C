#include <stdio.h>

int main()
{
    float a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3;
    float square1,square2,square3;
    scanf("%f %f %f %f",&a1,&b1,&c1,&d1); getchar();
    scanf("%f %f %f %f",&a2,&b2,&c2,&d2); getchar();
    scanf("%f %f %f %f",&a3,&b3,&c3,&d3); getchar();
    
    square1 = a1/1 + b1/2 + c1/3 + d1/4 +
              b1/2 + c1/3 + d1/4 + c1/3 +
              c1/3 + d1/4 + c1/3 + b1/2 +
              d1/4 + c1/3 + b1/2 + a1/1;
    square2 = a2/1 + b2/2 + c2/3 + d2/4 +
              b2/2 + c2/3 + d2/4 + c2/3 +
              c2/3 + d2/4 + c2/3 + b2/2 +
              d2/4 + c2/3 + b2/2 + a2/1;
    square3 = a3/1 + b3/2 + c3/3 + d3/4 +
              b3/2 + c3/3 + d3/4 + c3/3 +
              c3/3 + d3/4 + c3/3 + b3/2 +
              d3/4 + c3/3 + b3/2 + a3/1;
    
    printf("%.2f\n",square1);
    printf("%.2f\n",square2);
    printf("%.2f\n",square3);
    return 0;
}