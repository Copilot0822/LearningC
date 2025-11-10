/* Lab7 Part2 : analysis of text */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 1000 /* The maximum number of characters in a line of input */

int main()
{
  char text[MAX], c;
  int i;
  int lowercase, uppercase, digits, other;
  int length;

  puts("Type some text (then ENTER):");

  /* Save typed characters in text[]: */

  for (i = 0; i < MAX; i++)
  {
    text[i] = getchar();
    if (text[i] == '\n')
      break;
  }
  length = i; // Actual length of input string

  /* Analyze contents of text[]: */

  for (i = lowercase = uppercase = digits = other = 0; i < length; i++)
  {
    c = text[i];
    if (c >= 'a' && c <= 'z')
      lowercase++;
    else if (c >= 'A' && c <= 'Z')
      uppercase++;
    else if (c >= '0' && c <= '9')
      digits++;
    else
    {
      if (c == '\n')
        break;
      other++;
    }
  }

  puts("\nYou typed:");
  printf("A string with %d characters\n", length);
  printf("\t%d lower case letters\n", lowercase);
  printf("\t%d upper case letters\n", uppercase);
  printf("\t%d digits\n", digits);
  printf("\t%d others\n", other);

  int ig = 0;
  int j = length - 1;
  int isPal = 0;

  // printf("%d", length);
  // printf("    %d    ", length);
  while ((ig <= length / 2 && !(length % 2)) || (length % 2) && ig <= floor(length / 2))
  {
    isPal = 1;
    // printf("%c %c\n", text[ig], text[j]);
    if (!(text[ig] == text[j]))
    {
      isPal = 0;
      break;
    }
    ig++;
    j--;
  }

  if (isPal)
  {
    printf("the word is a palandrome");
  }
  else
  {
    printf("the word is not a palandrome");
  }
}
