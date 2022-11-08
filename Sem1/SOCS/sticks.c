#include <stdio.h>

int main()
{
    long long int jumTC;
    scanf("%lld",&jumTC); getchar();
    for(int i = 0; i < jumTC; i++)
    {
        long long int angka1, angka2, angka3;
        scanf("%lld %lld %lld",&angka1, &angka2, &angka3); getchar();
        if (((angka1 + angka2) > angka3) && ((angka1 + angka3) > angka2) && ((angka2 + angka3) > angka1))
        {
            printf("Case #%d: Yes",i+1);
        }
        else
        {
            printf("Case #%d: No",i+1);
        }
        printf("\n");
    }
    return 0;
}