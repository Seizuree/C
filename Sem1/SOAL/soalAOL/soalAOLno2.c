#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct appdata
{
  char nama[50];
  char nomor[50];
  char alamat[50];
};

int main()
{
  system("color 02");
  struct appdata data[50];
  int a;
  printf("Enter the amount of data you want to input : ");
  scanf("%d",&a); getchar();
  system("cls");
  for (int i = 1; i <= a; i++)
  {
    printf("Enter a name for the data (%d) : ",i);
    scanf("%[^\n]",&data[i].nama); getchar();
    printf("Enter the phone number for the data (%d) : ",i);
    scanf("%[^\n]",&data[i].nomor); getchar();
    printf("Enter the home address for the data (%d) : ",i);
    scanf("%[^\n]",&data[i].alamat); getchar();
    system("cls");
  }
  char pilihan[50];
  char reload;
  do {
    printf("Enter a name for the data you want to search : ");
    scanf("%s",&pilihan); getchar();
    int b = 0;
    for(int i = 1; i <= a; i++)
    {
      if(strstr(data[i].nama,pilihan) != 0)
      {
        printf("===============================================================\n");
        printf("| %-10s | %-13s | %-30s |\n", data[i].nama, data[i].nomor, data[i].alamat);
        b = 1;
      }
    }
    if(b != 1)
    {
      printf("Data Not Exist.\n");
    }
    else
    {
      printf("===============================================================\n");
    }
    printf("Do you want to repeat this program (Y/N) : ");
    scanf("%c",&reload); getchar();
    system("cls");
  } while(reload == 'Y' || reload == 'y');
  if(reload == 'N' || reload == 'n')
  {
    printf("Thank you for running this program.\n");
    getchar();
  }

  return 0;
}
