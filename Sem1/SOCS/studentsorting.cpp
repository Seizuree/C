#include <stdio.h>
#include <string.h>

struct datacenter{
    char nim[20];
    char nama[100];
};

void BubbleSort(struct datacenter data[], int len)
{
    for(int i = 0; i < len-1; i++)
    {
        for(int j = 0; j < len-1-i; j++)
        {
            if(strcmp (data[j].nim, data[j+1].nim) > 0)
            {
                datacenter temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

int main()
{
    FILE *fptr = fopen("testdata.in", "r");
    int tc;
    datacenter data[1001];
    while(!feof(fptr))
    {
        fscanf(fptr, "%d\n", &tc);
        for(int i = 0; i < tc; i++)
        {
            fscanf(fptr, "%10s %[^\n]\n", &data[i].nim, &data[i].nama);
        }
    }
    fclose(fptr);
    BubbleSort(data, tc);
    for(int i = 0; i < tc; i++)
    {
        printf("%s %s\n", data[i].nim, data[i].nama);
    }
    return 0;
}