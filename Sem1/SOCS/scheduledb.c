#include <stdio.h>

struct db{
	char code[20];
	char day[30];
	int time;
};

int main()
{
	int bnyk;
	scanf("%d", &bnyk);
	
	struct db arr[bnyk+1];
	for(int i = 0; i < bnyk; i++)
	{
		scanf("%s",&arr[i].code);
		scanf("%s",&arr[i].day);	
		scanf("%d",&arr[i].time);	
	}
	
	int test;
	scanf("%d", &test);
	for(int i = 0; i < test; i++){
		int a;
		scanf("%d", &a);
		printf("Query #%d:\n",i+1);
		printf("Code: %s\n", arr[a-1].code);
		printf("Day: %s\n", arr[a-1].day);
		printf("Time: %02d:00\n", arr[a-1].time);
	}
	
	return 0;
}
