#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
 char str1[80],str2[80];
 clrscr();
 puts("Enter the string : ");
 gets(str1);
 for (int i=strlen(str1)-1; i>=0; i--)
  str2[strlen(str1)c-i-1]=str1[i];
 puts(str2);
 getch();
}