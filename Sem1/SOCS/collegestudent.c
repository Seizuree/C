#include <stdio.h>

struct studentsData 
{
    char nama[101];
    char nim[10];
    int umur;
    char postCode[10];
    char placeOfBirth[101];
    char dateOfBirth[101];
    char highSchool[101];
    int numberOfSiblings;
    int height;
    char bankAccountNumber[10];
};

int main()
{
    int bnyk;
    scanf("%d",&bnyk); getchar();
    struct studentsData sd[150];
    for(int i = 0; i < bnyk; i++)
    {
        scanf("%[^\n]",sd[i].nama); getchar();
        scanf("%s", sd[i].nim); getchar();
        scanf("%d",&sd[i].umur); getchar();
        scanf("%s",sd[i].postCode); getchar();
        scanf("%[^\n]",sd[i].placeOfBirth); getchar();
        scanf("%[^\n]",sd[i].dateOfBirth); getchar();
        scanf("%[^\n]",sd[i].highSchool); getchar();
        scanf("%d",&sd[i].numberOfSiblings); getchar();
        scanf("%d",&sd[i].height); getchar();
        scanf("%s",sd[i].bankAccountNumber); getchar();
    }
    for(int i = 0; i < bnyk; i++)
    {
        printf("Mahasiswa ke-%d:\n",i+1);
        printf("Nama: %s\n",sd[i].nama); 
        printf("NIM: %s\n",sd[i].nim);
        printf("Umur: %d\n",sd[i].umur);
        printf("Kode Pos: %s\n",sd[i].postCode);
        printf("Tempat Lahir: %s\n",sd[i].placeOfBirth);
        printf("Tanggal Lahir: %s\n",sd[i].dateOfBirth);
        printf("Almamater SMA: %s\n",sd[i].highSchool);
        printf("Jumlah Saudara Kandung: %d\n",sd[i].numberOfSiblings);
        printf("Tinggi Badan: %d\n",sd[i].height);
        printf("NOMOR REKENING: %s\n",sd[i].bankAccountNumber);
    }
    return 0;

}