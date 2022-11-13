#include <stdio.h>
#include <stdlib.h>

int comparation(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int array[205] = {0};
    int count = 0, balancer = 0;
    scanf("%d %d",&count, &balancer);
    int totalTeam = 0;
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &array[i]);
    }
    qsort(array, count, sizeof(int), comparation);
    for (int i = 0; i < count-2; i++)
    {
        for (int j = i+1; j < count-1; j++)
        {
            for (int k = j+1; k < count; k++)
            {
                if (k == i || k == j)
                {
                    continue;
                }
                if ((array[k] - array[i]) > balancer)
                {
                    break;
                }
                totalTeam++;
                sum = array[i] + array[j] + array[k];
            }
        }
    }
    if (totalTeam == 0)
    {
        printf("-1\n");
    }
    else printf("%d %d",totalTeam, sum);
    return 0;
}