#include "stack.h"
#include <string.h>

void main()
 {
  char st[80];
  char flag=1;
  int letter;
  int len;
  STACK palindrom;
  clrscr();
  puts("Enter the string : ");
  gets(st);
  len=strlen(st);
  init_stack(&palindrom,len/2);
  for (int i=0; i<len/2; i++)
    push_stack(&palindrom,st[i]);
  for (i=0; i<len/2; i++)
   {
    pop_stack(&palindrom,&letter);
    if (letter!=st[len/2+i+len%2])
     flag=0;
   }
   delete_stack(&palindrom);
   if (flag) puts("This string is palindrome.");
   else puts("This string is not palindrom.");
   getch();
 }