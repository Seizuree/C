#include <stdio.h>
#include <string.h>

struct matpel
{
    char matpel[100];
    long long int jumMatpel;
};

int main()
{
    int tc;
    scanf("%d",&tc); getchar();
    matpel arr[tc+5];
    for (int i = 0; i < tc; i++)
    {
        scanf("%s %lld",arr[i].matpel,&arr[i].jumMatpel);
    }
    for (int i = 0; i < tc; i++)
    {
        for (int j = 0; j < tc - 1 - i; j++)
        {
            if(arr[j].jumMatpel > arr[j+1].jumMatpel)
            {
                long long int temporary = arr[j].jumMatpel;
                arr[j].jumMatpel = arr[j+1].jumMatpel;
                arr[j+1].jumMatpel = temporary;

                char temp[100] = {0};
                strcpy(temp, arr[j].matpel);
                strcpy(arr[j].matpel, arr[j+1].matpel);
                strcpy(arr[j+1].matpel, temp);
            }
            if(arr[j].jumMatpel == arr[j+1].jumMatpel)
            {
                if (strcmp(arr[j].matpel, arr[j+1].matpel) > 0)
                {
                    char temp[100] = {0};
                    strcpy(temp, arr[j].matpel);
                    strcpy(arr[j].matpel, arr[j+1].matpel);
                    strcpy(arr[j+1].matpel, temp);    
                }
            }
        }
    }
    for (int i = 0; i < tc; i++)
    {
        printf("%s\n",arr[i].matpel);
    }
    return 0;
}