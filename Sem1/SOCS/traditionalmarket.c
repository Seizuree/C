#include <stdio.h>

int main()
{
    long long int meat,green,egg;
    scanf("%lld %lld %lld",&meat,&green,&egg); getchar();
    if(meat>green&&green>egg)
    {
    printf("Daging\n");
    printf("Sayur\n");
    printf("Telur\n");
    }
    else if(green>egg&&egg>meat)
    {
    printf("Sayur\n");
    printf("Telur\n");
    printf("Daging\n");
    }
    else if(egg>meat&&meat>green)
    {
    printf("Telur\n");
    printf("Daging\n");
    printf("Sayur\n");
    }
    else if(meat>egg&&egg>green)
    {
    printf("Daging\n");
    printf("Telur\n");
    printf("Sayur\n");
    }
    else if(green>meat&&meat>egg)
    {
    printf("Sayur\n");
    printf("Daging\n");
    printf("Telur\n");
    }
    else
    {
    printf("Telur\n");
    printf("Sayur\n");
    printf("Daging\n");
    }
    return 0;
}