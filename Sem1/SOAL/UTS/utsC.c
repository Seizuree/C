// #include <stdio.h>

// int main() {
//     int n;
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++) {
//         int p, k;
//         scanf("%d %d", &p, &k);
//         int arrp[p + 5];
//         int arrk[k + 5];
//         for(int j = 0; j < p; j++) 
//         {
//             scanf("%d", &arrp[j]); getchar();
//         }
//         for(int x = 0; x < k; x++) 
//         {
//             scanf("%d", &arrk[x]); getchar();
//         }
//         for(int y = 0; y < p; y ++) 
//         {
//             int res;
//             if(y < (p - k + 1))
//             {
//                 res = 0;
//                 int aa = y;
//                 for(int z = y; z < (y + k - 1); z++) 
//                 {
//                     //printf("%d = %d + (%d - %d\n)", res, res, arrp[aa], arrk[z]);
//                     res = res + (arrp[aa] - arrk[z]);
//                     aa++;
//                 }
//                 printf("%d ", res);
//             }
//             else if(y < (p - k)) 
//             {
//                 res = 0;
//                 int aa = y;
//                 for(int z = y; z < (y + k - 1); z++) 
//                 {
//                     //printf("%d = %d + (%d - %d\n)", res, res, arrp[aa], arrk[z]);
//                     res = res + (arrp[aa] - arrk[z]);
//                     aa++;
//                 }
//                 printf("%d ", res);
//             }
//             else
//             {
//                 printf("\n");
//             }
//         }
//     }
// }

#include <stdio.h>

int main() {
    int n, p, k;
    scanf("%d", &n);
    getchar();
    
    for(int x=0; x<n; x++) 
    {
        scanf("%d %d", &p, &k);
        getchar();
        
        int arrp[p + 5];
        for(int x=0; x<p; x++) 
        {
            scanf("%d",&arrp[x]);
            getchar();
        }
        
        int arrk[k + 5];
        for(int x=0; x<k; x++) 
        {
            scanf("%d", &arrk[x]);
            getchar();
        }
        
        int whitespace = 1;
        
        for(int x=0; x<p; x++) 
        {
            int res = 0;
            if(p < (x + k)) 
            {
                break;
            }
            if(whitespace == 0) 
            {
                printf(" ");
            }
            for(int y = 0; y < k; y++) 
            {
                res = res + (arrp[x + y] ^ arrk[y]);
            }
            printf("%d", res);
            whitespace = 0;
        }
        printf("\n");
    }
}