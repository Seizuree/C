#include <stdio.h>
#include <stdlib.h>

int main()
{
    char choices;
    system("color 02");
    do
    {
        system("cls");
        int count = 0;
        printf("Input the size of the matrix : ");
        scanf("%d",&count); getchar();
        system("cls");

        int arr1[count+5][count+5];
        int sizeArr1 = 0;
        printf("Input the first matrix : \n");
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count; j++)
            {
                scanf("%d",&arr1[i][j]); getchar();
                if(arr1[i][j] == 1)
                {
                    sizeArr1++;
                }
            }
        }

        int arr2[count+5][count+5];
        int sizeArr2 = 0;

        printf("\nInput the second matrix : \n");
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count; j++)
            {
                scanf("%d",&arr2[i][j]); getchar();
                if (arr2[i][j] == 1)
                {
                    sizeArr2++;
                }
            }
        }

        system("cls");

        if (sizeArr1 > sizeArr2)
        {
            printf("Object 1 is bigger\n");
        }
        else if (sizeArr1 < sizeArr2)
        {
            printf("Object 2 is bigger\n");
        }
        else
        {
            printf("Object 1 and 2 has the same size\n");
        }
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
