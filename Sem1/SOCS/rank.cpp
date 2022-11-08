#include <stdio.h>
#include <string.h>

struct rank
{
    char nama[100];
    int nilai;
};

void sorting(rank *peringkat, int x)
{
    for (int i = 0; i < x - 1; i++)
    {
        for (int j = i+1; j < x; j++)
        {
            if (peringkat[j].nilai > peringkat[i].nilai)
            {
                rank temp = peringkat[j];
                peringkat[j] = peringkat[i];
                peringkat[i] = temp;
            }
            else if (peringkat[j].nilai == peringkat[i].nilai)
            {
                if (strcmp(peringkat[i].nama, peringkat[j].nama) > 0)
                {
                    rank temp = peringkat[i];
                    peringkat[i] = peringkat[j];
                    peringkat[j] = temp;
                }
            }
        }
    }
}

int main()
{
    int count;
    struct rank peringkat[1001];
    char tujuan[1000];
    scanf("%d",&count); getchar();
    for (int i = 0; i < count; i++)
    {
        int tc;
        int temp = 0;
        scanf("%d",&tc); getchar();
        for (int j = 0; j < tc; j++)
        {
            scanf("%[^#]#%d",&peringkat[j].nama,&peringkat[j].nilai); 
            getchar();
        }
        
        sorting(peringkat,tc);
        scanf("%s",&tujuan); getchar();
        
        printf("Case #%d: ",i+1);
        for (int j = 0; j < tc; j++)
        {
            if (strcmp (peringkat[j].nama, tujuan) == 0)
            {
                printf("%d\n",j+1);
            }
        }
    }
}