#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

char expiredDate[100] = {};

int counter = 0;

void createProductID(const char category[])
{
    for (int i = counter+1; i <= 100; i++)
    {
        if (category[0] == 'H' || category[0] == 'F' || category[0] == 'D')
        {
            if (i < 100)
            {
                printf("%c%03d\n",category[0],i);
                counter++;
                break;
            }
            if (i < 10)
            {
                printf("%c%02d\n",category[0],i);
                counter++;
                break;
            }
            if(i == 100)
            {
                printf("%c%d\n",category[0],i);
                counter++;
                break;
            }
        }
    }
}

void randomDate()
{
    int date = rand() % (30 - 1) + 1;
    int month = rand() % (12 -1) + 1;
    int year =  rand() % (25 - 20) + 20;
    sprintf(expiredDate, "%d/%d/%d",date,month,year);
}

void clearTemp(char target[])
{
    for (int i = 0; i < strlen(target); i++)
    {
        target[i] = '\0';
    }
}

// void validEmail(char target[])
// {
//     for (int i = 0; strlen(target) > i; i++)
//     {
//         if (target[i] == )
//         {
            
//         }
        
//     }
    
// }

int main()
{
    // srand(time(NULL));
    // randomDate();
    // printf("%s",expiredDate);
    createProductID("Health");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");
    createProductID("Food");

}