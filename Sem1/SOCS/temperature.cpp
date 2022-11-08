#include <stdio.h>
#include <string.h>

struct temperature
{
    char nama[2000];
    float suhu;
    char unit;
};

int main()
{
    FILE *fptr;
    temperature arr[205];
    int count = 0;
    float temp1;
    char temp2[2000];
    char temp3;
    fptr = fopen("testdata.in","r");
    while (!feof(fptr))
    {
        fscanf(fptr,"%[^#]#%f#%c\n",arr[count].nama,&arr[count].suhu, &arr[count].unit);
        count++;
    }
    fclose(fptr);
    for (int i = 0; i < count; i++)
    {
        if(arr[i].unit == 'F')
        {
            arr[i].suhu = (arr[i].suhu - 32) * 5/9;
        }
    }
    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if(arr[j].suhu > arr[j+1].suhu)
            {
                temp1 = arr[j+1].suhu;
                arr[j+1].suhu = arr[j].suhu;
                arr[j].suhu = temp1;

                strcpy(temp2, arr[j+1].nama);
                strcpy(arr[j+1].nama,arr[j].nama);
                strcpy(arr[j].nama, temp2);

                temp3 = arr[j+1].unit;
                arr[j+1].unit = arr[j].unit;
                arr[j].unit = temp3;
            }
            else if (arr[j].suhu == arr[j+1].suhu)
            {
                if(strcmp(arr[j].nama, arr[j+1].nama) > 0)
                {
                    strcpy(temp2, arr[j+1].nama);
                    strcpy(arr[j+1].nama, arr[j].nama);
                    strcpy(arr[j].nama, temp2);
                }
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        if(arr[i].unit == 'F')
        {
            arr[i].suhu = (arr[i].suhu * 9 / 5) + 32;
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s is %0.2f%c\n", arr[i].nama, arr[i].suhu, arr[i].unit);
    }
    return 0;    
}