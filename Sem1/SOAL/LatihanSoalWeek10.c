#include <stdio.h>
#include <string.h>

struct BNCCweek10
{
    char nama[100];
    char notelp[100];
};

int main()
{
    struct BNCCweek10 kontak[100];
    FILE *fptr;
    fptr = fopen("contacts.txt","r");
    int i = 0;
    int count = 0;
    while (!feof(fptr))
    {
        fscanf(fptr,"%[^,],%[^\n]\n",kontak[i].nama,kontak[i].notelp);
        i++;
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count-i-1; j++)
        {
            if (strcmp(kontak[j].nama, kontak[j+1].nama) > 0)
            {
                char tempKontak[100];
                strcpy(tempKontak, kontak[j+1].nama);
                strcpy(kontak[j+1].nama, kontak[j].nama);
                strcpy(kontak[j].nama, tempKontak);

                char tempNo[100];
                strcpy(tempNo, kontak[j+1].notelp);
                strcpy(kontak[j+1].notelp, kontak[j].notelp);
                strcpy(kontak[j].notelp, tempNo);
            }
            // else if (strcmp(kontak[j].nama, kontak[j+1].nama) < 0)
            // {
            //     char tempKontak[100];
            //     strcpy(tempKontak, kontak[j+1].nama);
            //     strcpy(kontak[j+1].nama, kontak[j].nama);
            //     strcpy(kontak[j].nama, tempKontak);

            //     char tempNo[100];
            //     strcpy(tempNo, kontak[j+1].notelp);
            //     strcpy(kontak[j+1].notelp, kontak[j].notelp);
            //     strcpy(kontak[j].notelp, tempNo);
            // }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s: (%s)\n",kontak[i].nama, kontak[i].notelp);
    }
}