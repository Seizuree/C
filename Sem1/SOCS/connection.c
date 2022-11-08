#include <stdio.h>
#include <string.h>

struct student
{
    char studentCode[35];
    char studentName[35];
    char studentGender[35];
    char father[35];
    char mother[35];
    int totalStudent;
};

struct lecturer
{
  char lecturerCode[35];
  char lecturerName[35];
  char lecturerGender[35];
  int total;
  struct student siswa[101];
};

int main()
{
    int bnyk;
    scanf("%d",&bnyk); getchar();
    struct lecturer dosen[101];
    for(int i = 1; i <= bnyk; i++)
    {
      scanf("%s",&dosen[i].lecturerCode); getchar();
      scanf("%[^\n]",&dosen[i].lecturerName); getchar();
      scanf("%[^\n]",&dosen[i].lecturerGender); getchar();
      scanf("%d",&dosen[i].total); getchar();
      for(int j = 1; j <= dosen[i].total;j++)
      {
        scanf("%s",&dosen[i].siswa[j].studentCode); getchar();
        scanf("%[^\n]",&dosen[i].siswa[j].studentName); getchar();
        scanf("%[^\n]",&dosen[i].siswa[j].studentGender); getchar();
        scanf("%[^\n]",&dosen[i].siswa[j].father); getchar();
        scanf("%[^\n]",&dosen[i].siswa[j].mother); getchar();
        scanf("%d",&dosen[i].siswa[j].totalStudent); getchar();
      }
    }
    int x;
    scanf("%d",&x); getchar();
    printf("Kode Dosen: %s\n",dosen[x].lecturerCode);
    printf("Nama Dosen: %s\n",dosen[x].lecturerName);
    printf("Gender Dosen: %s\n",dosen[x].lecturerGender);
    printf("Jumlah Mahasiswa: %d\n",dosen[x].total);
    for(int k = 1; k <= dosen[x].total; k++)
    {
      printf("Kode Mahasiswa: %s\n",dosen[x].siswa[k].studentCode);
      printf("Nama Mahasiswa: %s\n",dosen[x].siswa[k].studentName);
      printf("Gender Mahasiswa: %s\n",dosen[x].siswa[k].studentGender);
      printf("Nama Ayah: %s\n",dosen[x].siswa[k].father);
      printf("Nama Ibu: %s\n",dosen[x].siswa[k].mother);
      printf("Jumlah Saudara Kandung: %d\n",dosen[x].siswa[k].totalStudent);
    }
    return 0;
}
