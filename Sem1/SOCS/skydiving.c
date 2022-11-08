#include <stdio.h>

int main()
{
    char nama1[100], nama2[100];
    double tinggi1, tinggi2;
    int umur1, umur2;

    scanf("%s", &nama1);
    scanf("%lf",&tinggi1); 
    scanf("%d",&umur1); 
    scanf("%s", &nama2); 
    scanf("%lf",&tinggi2); 
    scanf("%d",&umur2); 
    getchar();

    printf("Name 1: %s\n", nama1);
    printf("Height 1: %.2lf\n",tinggi1);
    printf("Age 1: %d\n",umur1);
    printf("Name 2: %s\n",nama2);
    printf("Height 2: %.2lf\n",tinggi2);
    printf("Age 2: %d\n",umur2);

    return 0;
}