
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 5
int def(char *);
void check(FILE *, char **);
int integer(char *);
int character(char *);
int floater(char *);
int longer(char *);
int doubler(char *);
int scopes(char *);

int Memory[MAX] = {NULL};

void main(void)
{
  clrscr();
  FILE *fptr;
  char pFilename[50] = {"a:\\bdika.cpp"};
  char *str[MAX] = {"int", "char", "float", "double", "long"};

  if ((fptr = fopen(pFilename, "r")) == NULL)
  {
    printf("\aCan't open file!");
    exit(1);
  }
  check(fptr, str);
  fclose(fptr);
}

void check(FILE *fptr, char **str)
{
  char word[50] = {NULL};
  int count = 0;
  int SInt = 0, SChar = 0, SFloat = 0, SDouble = 0, SLong = 0;
  char row[90];
  do
  {
    fgets(row, 80, fptr);
    sscanf(row, "%s", word);
    for (count = 0; count < MAX; count++)
    {
      if (!strcmpi(word, str[count]))
      {
        switch (count)
        {
        case 0:
        {
          SInt += integer(row);
          break;
        }
        case 1:
        {
          SChar += character(row);
          break;
        }
        case 2:
        {
          SFloat += floater(row);
          break;
        }
        case 3:
        {
          SDouble += doubler(row);
          break;
        }
        case 4:
        {
          SLong += longer(row);
          break;
        }
        default:
        {
          printf("\aERROR!");
          return;
        }
        }
      }
    }
  } while (!feof(fptr));
  printf("Integer = %d\n", SInt);
  printf("Char    = %d\n", SChar);
  printf("Float   = %d\n", SFloat);
  printf("Double  = %d\n", SDouble);
  printf("Long    = %d\n", SLong);
}
//----------------------------------
int integer(char *row)
{
  char word[20] = {NULL};
  int sum = 0;

  while (!isalpha(*row))
    row++;
  row = row + 4;
  do
  {
    sscanf(row, "%s", word);
    sum += 2 * scopes(word);
    row += strlen(word) + 1;
  } while (*row != '\n' && *row != ';');
  return sum;
}
//-----------------------------------

int character(char *row)
{
  char word[20] = {NULL};
  int sum = 0;

  while (!isalpha(*row))
    row++;
  row = row + 5;
  do
  {
    sscanf(row, "%s", word);
    sum += 1 * scopes(word);
    row += strlen(word) + 1;
  } while (*row != '\n' && *row != ';');
  return sum;
}
int floater(char *row)
{
  char word[20] = {NULL};
  int sum = 0;

  while (!isalpha(*row))
    row++;
  row = row + 6;
  do
  {
    sscanf(row, "%s", word);
    sum += 4 * scopes(word);
    row += strlen(word) + 1;
  } while (*row != '\n' && *row != ';');
  return sum;
}
int longer(char *row)
{
  char word[20] = {NULL};
  int sum = 0;

  while (!isalpha(*row))
    row++;
  row = row + 5;
  do
  {
    sscanf(row, "%s", word);
    sum += 4 * scopes(word);
    row += strlen(word) + 1;
  } while (*row != '\n' && *row != ';');
  return sum;
}
int doubler(char *row)
{
  char word[20] = {NULL};
  int sum = 0;

  while (!isalpha(*row))
    row++;
  row = row + 7;
  do
  {
    sscanf(row, "%s", word);
    sum += 8 * scopes(word);
    row += strlen(word) + 1;
  } while (*row != '\n' && *row != ';');
  return sum;
}
//-----------------------------------------
int scopes(char *word)
{
  int num = 1;
  while (*word != '\0' && *word != ';' && *word != ',')
  {
    if (*word == '[')
    {
      word++;
      num *= atoi(word);
      while (*word != ']')
        word++;
      if (*(++word) == '[')
      {
        num *= atoi(++word);
      }
    }
    word++;
  }
  return num;
}