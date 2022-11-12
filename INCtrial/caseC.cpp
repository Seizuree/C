#include <stdio.h>
#include <string.h>

#define MAX 500

void reverseString(char *str, char *reverse_str)
{
	int nLengthStr = strlen(str);
    int i,j;

	for (i = nLengthStr-1, j = 0; i >= 0; i--,j++)  
    {  
    	reverse_str[j] = str[i];
    }
}


int main()
{
	char string_to_check[MAX];
	char left_str[MAX];
	char right_str[MAX];
	char reverse_str[MAX];
	int printString = 0;
    int length, i;
	scanf("%[^\n]",&string_to_check); getchar();

	if(strlen(string_to_check) == 1 )
	{
		return 0;
	}
	else if ( strlen(string_to_check) == 2  )
	{
		memset(left_str, '\0', sizeof(left_str));
		strncpy ( left_str, string_to_check, 1 );
		memset(right_str, '\0', sizeof(right_str));
		strncpy ( right_str, &string_to_check[1], 1 );
	}
	else if ( strlen(string_to_check) > 2  )
	{
		length = strlen(string_to_check);

		for( i = 2; i < length; i++)
		{
			memset(left_str, '\0', sizeof(left_str));
			strncpy ( left_str, string_to_check, i );
			memset(reverse_str, '\0', sizeof(reverse_str));
			reverseString(left_str, reverse_str);
			
			if ( strcmp(left_str, reverse_str) == 0 )
			{
				printString = 1;
				memset(right_str, '\0', sizeof(right_str));
				strncpy ( right_str, &string_to_check[i], length - i );
				memset(reverse_str, '\0', sizeof(reverse_str));
				reverseString(right_str, reverse_str);

				if (strcmp(right_str, reverse_str) == 0 )
				{
					break;
				}
				else
				{
					printString = 0;
				}
			}
		}
	}
	else
	{
		return 0;
	}
	if(printString)
	{
		printf("%s %s \n",left_str,right_str);
	}
	else
	{
		printf("NO");
	}

	return 0;
}
