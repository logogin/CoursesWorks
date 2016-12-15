#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
void main ()
 {
  char *str1,*str2;
  char ch;
  int i=0,j=0;
  clrscr();
  str1=(char *)malloc(100);
  str2=(char *)malloc(100);
  puts("Enter the string (\"!\" - end): ");
  while ((ch=getchar())!='!')
   {
    if (ch<='9' && ch>='0')
     str1[i++]=ch;
    if ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
     str2[j++]=ch;
   }
  str1[i]='\x0';
  str2[j]='\x0';
  puts("");
  puts("Numbers in the string are :");
  puts(str1);
  puts("Letters in the string are :");
  puts(str2);
  getch();
 }