#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removespace(char *kalimat)
{
    char* space = kalimat;
    do {
        while (*space == ' ')
        {
            ++space;
        }
    } while (*kalimat++ = *space++);
}

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
    scanf("%d",&bnyk); getchar();
    char kalimat[500];
    for(int i = 0; i < bnyk; i++)
    {
        scanf("%[^\n]",&kalimat); getchar();
        int len = strlen(kalimat);
        for(int j = 0; j < len+1; j++)
        {
            kalimat[j] = tolower(kalimat[j]);
        }
        removespace(kalimat);
        cekPalindrome(kalimat);
    }
    return 0;
}