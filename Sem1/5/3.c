#include <stdio.h>
#include <string.h>

int main()
{
  int total = 0;
  char name[200];
  for (int i = 0; i < strlen(name); i++)
  {
    name[i] = ' ';
  }
  scanf("%d %s",&total, &name);
  for (int i = 0; i < total; i++)
  {
    if (i % 2 == 0)
    {
      printf("Hello Mr. %s\n",name);
    }
    else
    {
      printf("Hello Mrs. %s\n",name);
    }
  }
  return 0;
}