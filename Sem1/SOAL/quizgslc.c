#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void printMenu()
{
  puts("SPECIAL PREMIUM LOTTERY");
  puts("=======================\n");
  puts("No | Prize                                   |");
  puts("----------------------------------------------");
  puts(" 1 | 1 Million US Dollar Cash                |");
  puts(" 2 | NEW RANGE ROVER SVAutobiography DYNAMIC |");
  puts(" 3 | Panasonic Smart TV  DX400               |");
  puts(" 4 | Polygon Helios F3 Red                   |");
  puts(" 5 | iPhone X 256GB                          |");
  puts("");
  puts("Menu");
  puts("----");
  puts("1. Buy a lottery");
  puts("2. View buyer");
  puts("3. Choose the winner");
  puts("");
  printf("Choose your option : ");
}

struct lottery
{
  char lotteryOwner[50];
  long long int lotteryNumber;
};

int main()
{
  struct lottery ltr[25];
  int abc = 0;
  int option;
  int jumlah = 0;
  int len = 0;
  int x = 0;
  int y = 0;
  char prize[5][50] =
  { {"1 Million US Dollar Cash"},
    {"NEW RANGE ROVER SVAutobiography DYNAMIC"},
	  {"Panasonic Smart TV  DX400"},
    {"Polygon Helios F3 Red"},
    {"iPhone X 256GB"} };
  int userPrize;
  char cycle;
  int doorprizeNumber[10];
  int z = 0;

  do {
    printMenu();
    scanf("%d",&option); getchar();
    if(option == 1)
    {
      if(jumlah >= 20)
      {
        printf("Maximum 20 lottery number has been reached!!!\n");
        getchar();
        system("cls");
      }
      else
      {
        jumlah++;
  			x = 0;
  			do{
    			srand(time(0));
  		    ltr[jumlah].lotteryNumber = rand()%((9999999999-1000000000)+1)+1000000000;
  		    for(int i=1; i<jumlah; i++)
          {
  		    	if(ltr[jumlah].lotteryNumber == ltr[i].lotteryNumber)
            {
  		    		x = 1;
  		    		break;
  				  }
            else
            {
  					  x = 0;
  				  }
    			}
  			}while(x == 1);
        printf("\nYour lottery number is : %lld\n\n",ltr[jumlah].lotteryNumber);
        do {
          printf("Please fill up your name [3..25] : ");
          scanf("%[^\n]",ltr[jumlah].lotteryOwner); getchar();
          len = strlen(ltr[jumlah].lotteryOwner);
        } while(len < 3 || len > 25);
        printf("Thank you for buying a lottery ticket, we wish for your fortune...");
        getchar();
        system("cls");
      }
    }
    else if(option == 2)
    {
      if(jumlah == 0)
      {
        printf("\nThere's no buyer at this moment...");
        getchar();
        system("cls");
      }
      else
      {
        printf("\n| No | Lottery Number | Name\n");
			  printf("-----------------------------------------------\n");
        for (int i = 1; i <= jumlah; i++)
        {
          printf("| %.2d | %lld    | %s\n",i,ltr[i].lotteryNumber,ltr[i].lotteryOwner);
        }
        printf("\nPress ENTER to continue...");
        getchar();
        system("cls"); 
      }
    }
    else if(option == 3)
    {
      if(jumlah < 5)
      {
			printf("\nThere's not enough buyer to pick the winner");
			getchar();
			system("cls");
  		}
      else
      {
  			printf("\n| No | Prize                                    | Winner\n");
  			printf("--------------------------------------------------------------------------------\n");
  			for(int i=0; i<5; i++){
  				y = 0;
  				do{
  					userPrize = rand()%jumlah + 1;
  					doorprizeNumber[z] = userPrize;
  					for(int j=0; j<z; j++)
            {
  						if(userPrize == doorprizeNumber[j])
              {
  							y = 1;
  							break;
  						}
              else
              {
  							y = 0;
  						}
  					}
  				}while(y == 1);
  				printf("| %d. | %-40s | %lld - %s\n", i+1, prize[i], ltr[userPrize].lotteryNumber, ltr[userPrize].lotteryOwner);
  				++z;
  			}
  			printf("\nCongratulations for all winners!!!\n");
  			puts("");
  			do{
  				printf("New Cycle [y|n] : ");
  				scanf("%c", &cycle);
  				getchar();
  			}while(cycle != 'y' && cycle != 'Y' && cycle != 'n' && cycle != 'N');
  			if(cycle == 'n' || cycle == 'N'){
  				system("cls");
  				printf("Thankyou For Playing...\n");
  				printf("Have a nice day ^.^ ");
  				getchar();
  				break;
  			}else{
  				for(int i=1; i<=jumlah; i++){
  					ltr[i].lotteryNumber = 0;
  					strcpy(ltr[i].lotteryOwner, " ");
  					doorprizeNumber[i-1] = 0;
  				}
  				jumlah = 0;
  				z = 0 ;
  				system("cls");
  			}
  		}
    }
  } while(x != -1);
  return 0;
}
