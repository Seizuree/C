#include <stdio.h>
#include <string.h>

int main()
{
  FILE *p;
  p = fopen("testdata.in","r");
  int i, tc;
  fscanf(p,"%d\n",&tc);
  char nomor[tc][15] = {0};
  char kata2[tc][50] = {0};
  for (int i = 0; i < tc; i++)
  {
    fscanf(p, "%[^#]#%[^\n]\n",nomor[i],kata2[i]);
  }

  fclose(p);

  for (int i = 0; i < tc; i++)
  {
    for (int j = 0; j < tc-1; j++)
    {
      if (strcmp(kata2[j], kata2[j+1]) > 0)
      {
        char temp[1000];
        strcpy(temp, kata2[j]);
        strcpy(kata2[j], kata2[j+1]);
        strcpy(kata2[j+1], temp);

        char temp1[15];
        strcpy(temp1, nomor[j]);
        strcpy(nomor[j], nomor[j+1]);
        strcpy(nomor[j+1], temp1);
      }
    }
  }
  for (int i = 0; i < tc; i++)
  {
    printf("%s %s\n",nomor[i], kata2[i]);
  }
}
