// #include <stdio.h>

// char loc[105][105];
// int sum = 0;

// void floodfill(int x, int y)
// {
//     if(loc[x][y] != '.' && loc[x][y] != 'S'){
//         return;
//     }
//     else if(loc[x][y] == '.'){
//         loc[x][y] = '#';
//         sum++;
//     }

//     floodfill(x-1, y);
//     floodfill(x, y-1);
//     floodfill(x+1, y);
//     floodfill(x, y+1);
// }

// int main()
// {
//     int count;
//     scanf("%d", &count); getchar();

//     for(int a = 1; a <= count; a++)
// 	{
//         sum = 0;
//         char c;
//         int start_x, start_y;
// 		int row, col;
//         scanf("%d %d", &row, &col); getchar();
//         for(int i = 0; i < row; i++)
// 		{
//             for(int j = 0; j < col; j++)
// 			{
//                 scanf("%c", &loc[i][j]); 
//                 if(loc[i][j] == 'S')
// 				{
//                     start_x = i; start_y = j;
//                 }
//             }
// 			getchar();
//         }

//         floodfill(start_x, start_y);

//         printf("Case #%d: %d\n",a,sum);
//     } return 0;
// }

// #include <stdio.h>

// int sum = 0;

// void floodfill(char *map, int posX, int posY, int x, int y)
// {
// 	if(posX - 1 == '#' && posX + 1 == '#' && posY - 1 == '#' && posY + 1 == '#')
// 	{
// 		return;
// 	}
// 	else if(posX < 0 || posX > x - 1 || posY < 0 || posY > y - 1)
// 	{
// 		return;
// 	}
// 	else
// 	{
// 		if(*(map + posY + posX * y) == '.'){
// 			sum++;
// 		}
// 		*(map + posY + posX * y) = '#';
// 		if(*(map + posY + (posX + 1) * y) != '#'){
// 			floodfill(map, posX + 1, posY, x, y);
// 		}
// 		if(*(map + posY + (posX - 1) * y) != '#'){
// 			floodfill(map, posX - 1, posY, x, y);
// 		}
// 		if(*(map + (posY + 1) + posX * y) != '#'){
// 			floodfill(map, posX, posY + 1, x, y);
// 		}
// 		if(*(map + (posY - 1) + posX * y) != '#'){
// 			floodfill(map, posX, posY - 1, x, y);
// 		}
// 	}
// }

// int main(){
// 	int t;
// 	scanf("%d", &t);
	
// 	for(int i = 0; i < t; i++)
// 	{
// 		int x, y, posX, posY;

// 		scanf("%d %d", &x, &y); getchar();
// 		char loc[x+5][y+5];
		
// 		for(int j = 0; j < x; j++)
// 		{
// 			for(int k = 0; k < y; k++)
// 			{
// 				scanf("%c", &loc[j][k]);
// 				if(loc[j][k] == 'S'){
// 					posX = j;
// 					posY = k;
// 				}
// 			}
// 			getchar();
// 		}
// 		floodfill(*loc, posX, posY, x, y);
// 		printf("Case #%d: %d\n", i + 1, sum);
// 		sum = 0;
// 	}
// }
#include <stdio.h>

int total = 0;

void floodfill(char *map, int posX, int posY, int x, int y)
{
	if(posX - 1 == '#' && posX + 1 == '#' && posY - 1 == '#' && posY + 1 == '#')
	{
		return;
	}
	else if(posX < 0 || posX > x - 1 || posY < 0 || posY > y - 1)
	{
		return;
	}
	else
	{
		if(*(map + posY + posX * y) == '.')
		{
			total++;
		}
		*(map + posY + posX * y) = '#';
		if(*(map + posY + (posX + 1) * y) != '#')
		{
			floodfill(map, posX + 1, posY, x, y);
		}
		if(*(map + posY + (posX - 1) * y) != '#')
		{
			floodfill(map, posX - 1, posY, x, y);
		}
		if(*(map + (posY + 1) + posX * y) != '#')
		{
			floodfill(map, posX, posY + 1, x, y);
		}
		if(*(map + (posY - 1) + posX * y) != '#')
		{
			floodfill(map, posX, posY - 1, x, y);
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	
	for(int i = 0; i < t; i++)
	{
		int x, y, posX, posY;

		scanf("%d %d", &x, &y); getchar();
		char loc[x][y];
		
		for(int j = 0; j < x; j++)
		{
			for(int k = 0; k < y; k++)
			{
				scanf("%c", &loc[j][k]);
				if(loc[j][k] == 'S')
				{
					posX = j;
					posY = k;
				}
			}
			getchar();
		}
		floodfill(*loc, posX, posY, x, y);
		printf("Case #%d: %d\n", i + 1, total);
		total = 0;
	}
}
