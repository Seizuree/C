#include <stdio.h>

int main() 
{
    FILE *fptr;
    fptr = fopen("testdata.in","r");

    if (fptr == NULL) 
    {
        printf("File couldn't be opened!\n");
    } 
    else 
    {
        int words;
        fscanf(fptr, "%d", &words);

        int i = 1;
        int count[11];
        for (int j = 0; j <= 11; j++)
        {
            count[j] = 0;
        }
        

        char check;
        int point = 0;
        while ((check = fgetc(fptr)) != EOF) 
        {
            if (check >= 'A' && check <= 'Z' || check >= 'a' && check <= 'z') 
            {
                point = 1;
            }
            if (point == 1 && (check == ' ' || check == '\n' || check == '\t' || check == '\0')) 
            {
                count[i]++;
                point = 0;
            }
            if (check == '#') 
            {
                i++;
                point = 0;
            }
        } 
        fclose(fptr);
            
        int correct = 1;
        for(int j = 1; j < i; j++) 
        {
            if(count[j] < words) 
            {
                correct = 0;
                printf("page %d: %d word(s)\n", j, count[j]);
            }
        }

        if(correct == 1) 
        {
            printf("The essay is correct\n");
        }
    } 
    return 0;
}