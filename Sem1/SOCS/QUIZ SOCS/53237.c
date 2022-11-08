#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char inputs[10001];
    scanf("%[^\n]",&inputs);
    int length = strlen(inputs);
    for(int i = 0; i < length; i++)
    {
        inputs[i] = toupper(inputs[i]);
    }
    for(int i = 0; i < length; i++)
    {
        if(inputs[i] == 'I')
        {
            inputs[i] = '1';
        }
        if(inputs[i] == 'R')
        {
            inputs[i] = '2';
        }
        if(inputs[i] == 'E')
        {
            inputs[i] = '3';
        }
        if(inputs[i] == 'A')
        {
            inputs[i] = '4';
        }
        if(inputs[i] == 'S')
        {
            inputs[i] = '5';
        }
        if(inputs[i] == 'G')
        {
            inputs[i] = '6';
        }
        if(inputs[i] == 'T')
        {
            inputs[i] = '7';
        }
        if(inputs[i] == 'B')
        {
            inputs[i] = '8';
        }
        if(inputs[i] == 'P')
        {
            inputs[i] = '9';
        }
        if(inputs[i] == 'O')
        {
            inputs[i] = '0';
        }
    }
    printf("%s\n",inputs);
    return 0;
}