#include <bits/stdc++.h>

int x = -1;
int y = 0;

void compare(){
    if (y > x) {
        x = y;
    }
    y = 0;
}

int main () {
    int count;
    scanf("%d", &count);
    getchar();
    int arr[count+3];

    for (int i = 0; i < count; i++)
    {
        scanf("%d", &arr[i]);
		getchar();
    }


    for (int i = 0; i < count; i++)
    {
        if (arr[i]== 0)
        {
            if (i + 1 < count)
            {
                if (abs(arr[i-1] - arr[i+1]) == 0 || abs(arr[i-1] - arr[i+1]) == 2)
                {
                    y++;
                } 
                else 
                {
                    y++;
                    compare();
                    y++;
                }
                
            } 
            else 
            {
                y++;
            }
        } 
        else 
        {
            if (i + 2 < count) 
            {
                if (abs(arr[i] - arr[i+2]) == 0 || abs(arr[i] - arr[i+2]) == 2)
                {
                    y++;
                    continue;
                } 
                else 
                {
                    y+=2;
                    compare();
                }
            } 
            else
            {
                y++;
                continue;
            }
        }
    }
    compare();

    printf("%d\n", x);
}