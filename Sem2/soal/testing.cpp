#include <stdio.h>
#include <string.h>

int main()
{
  char input[255];
  scanf("%[^\n]",&input);
  int ctr = 0;
  char *p = strtok(input, " ");
  char *array[4];
  while (p != NULL)
  {
    array[ctr++] = p;
    p = strtok (NULL, " ");
  }
  printf("%s\n",array[0]);
  return 0;
}