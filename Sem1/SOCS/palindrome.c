#include <stdio.h>
#include <string.h>

void cekPalindrome(char kalimat[500])
{
    int a = 0;
    int b = strlen(kalimat) - 1;
    while (b > a)
    {
        if (kalimat[a++] != kalimat[b--])
        {
            printf("false\n");
            return;
        }
    }
    printf("true\n");
}


int main()
{
    int bnyk;
    scanf("%d",&bnyk);
    char kalimat[500];
    for(int i = 0; i < bnyk; i++)
    {
        scanf("%s",&kalimat);
        printf("Case #%d: ",(i+1));
        cekPalindrome(kalimat);
    }
    return 0;
}