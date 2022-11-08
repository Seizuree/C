#include<stdio.h>
#include<string.h>

int distinctionChar (char* katakata) 
{
	int temp[128] = {0};
	int count = 0;
	int len = strlen(katakata);
	for (int i = 0; i < len; ++i) 
    {
		temp[katakata[i]] = 1;
	}
	for (int i = 0; i < 128; ++i) 
    {
		count += temp[i];
	}
    return count;
}

int main() 
{
	int percobaan;
	char katakata[100000];
	scanf("%d",&percobaan);
	for (int i = 0; i < percobaan; i++)
    {
        scanf("%s",katakata);
        printf("Case #%d: ",i+1);
        
        if (distinctionChar(katakata) % 2 != 0)
        {
            printf("Unbreakable\n"); 
        }
        else 
        {
            printf("Breakable\n");
        }
    }
    return 0;
}