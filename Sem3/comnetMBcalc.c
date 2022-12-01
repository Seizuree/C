#include <stdio.h>

int main(){
    int a = 1;
    while (a == 1)
    {
        printf("Insert total user: ");
        int x = 0;
        scanf("%d",&x);
        int res = (x * 500)/1000;
        printf("Total bandwidth: %dMbps\n\n",res);
        printf("Press enter to continue!\n\n");
        getchar();
    }
    return 0;
}