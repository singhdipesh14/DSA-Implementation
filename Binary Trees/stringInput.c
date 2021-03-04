#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *s = (char *)calloc(20, sizeof(char));
  int i = 0;
  char ele;
  while (1)
  {
    scanf("%c", &s[i]);
    if (s[i] == '\n')
    {
      s[i] = '\0';
      break;
    }
    i++;
  }
  printf("%s", s);
}