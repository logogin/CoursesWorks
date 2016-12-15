#include <string.h>
#include "stack.h"
void main()
 {
  char st[80];
  char y[80];
  int i=0;
  int sizex=0;
  int sizey=0;
  int flag=1;
  int letter;
  STACK string;
  clrscr();
  puts("Enter the string ( XzYzX ) : ");
  gets(st);
  for (i=0;i<strlen(st);i++)
   if (st[i]!='a'&&st[i]!='b'&&st[i]!='z')
    flag=0;
  if (flag)
   {
    i=0;
    init_stack(&string,strlen(st));
    while (st[i]!='z')
     {
      sizex++;
      i++;
     }
    i++;
    while (st[i]!='z')
     {
      push_stack(&string,st[i]);
      i++;
      sizey++;
     }
    i=0;
    while (string.sp)
     {
      pop_stack(&string,&letter);
      y[i]=letter;
      i++;
     }
    y[i]='\x0';
    st[sizex]='\x0';
    if (strstr(st,y)==NULL)
     flag=0;
   }

  if (flag)
   {
    st[sizex]='z';
    for (i=0; i<strlen(st)-sizex-sizey-2; i++)
     if (st[i]!=st[i+sizex+sizey+2])
      flag=0;
   }

  if (flag) puts("String is matching to the rule.");
  else puts("String is not matching to the rule");
  delete_stack(&string);
  getch();
 }