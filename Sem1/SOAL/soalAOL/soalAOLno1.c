#include <stdio.h>
#include <stdlib.h>

int arr[500][500];
int ctr = 0;

void elementNearby(int a, int b)
{
  if (arr[a][b] > 0)
  {
    ctr++;
  }
  else
  {
    return;
  }

  if (ctr > 1 && arr[a][b] > 0)
  {
    printf("Nearest same element is at %d,%d\n",a,b);
  }

  if (ctr == 1)
  {
    elementNearby(a + 1, b);
    elementNearby(a, b + 1);
    elementNearby(a - 1, b);
    elementNearby(a, b - 1);
  }

  if (ctr == 1)
  {
    elementNearby(a + 1, b + 1);
    elementNearby(a - 1, b - 1);
    elementNearby(a - 1, b + 1);
    elementNearby(a + 1, b - 1);
  }

  if (ctr == 1)
  {
    printf("Nearest same element is at: no nearest element.\n");
  }
}

int main()
{
  char choices;
  system("color 02");
  system("cls");
  do
  {
    int count = 0;
    printf("Input the size of the matrix : ");
    scanf("%d",&count); getchar();

    system("cls");

    printf("Input the matrix : \n");
    for (int i = 0; i < count; i++)
    {
      for (int j = 0; j < count; j++)
      {
        scanf("%d",&arr[i][j]); getchar();
      }
    }

    system("cls");
    elementNearby(count/2,count/2);

    printf("\nDo you want to repeat this program (Y/N) : ");
    scanf("%c",&choices); getchar();
    system("cls");
  } while (choices == 'Y' || choices == 'y');
  if(choices == 'N' || choices == 'n')
  {
    printf("Thank you for running this program.\n");
    getchar();
  }
  return 0;
}
