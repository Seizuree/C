#include <stdio.h>
#include <string.h>

int main()
{
    int testcase;
    scanf("%d",&testcase); getchar();
    char kata[10000];
    for(int i = 0; i < testcase; i++)
    {
        scanf("%s",&kata); getchar();
        int len = strlen(kata);
        for(int j = 0; j < len; j++)
        {
            int space = 0;
            for(int x = j;; x++)
            {
                if(kata[x] == " " || kata[x+1] == '\0')
                {
                    space = x;
                    if(kata[x+1] == '\0')
                    {
                        space += 1;
                    }
                    break;
                }
            }
            int akhir = 0;
            for(int awal = j+1, akhir = space - 2; awal < akhir; awal++, akhir--)
            {
                char temp = kata[awal];
                kata[awal] = kata[akhir];
                kata[akhir] = temp;
            }
            if(space + 1 != len)
            {
                j = space;
            }
        }
        printf("Case #%d: %s\n", kata);
    }
    return 0;
}
