#include <stdio.h>
#include <conio.h>
void main()
{
 unsigned char ch;
 clrscr();
 puts("Enter the string (\".\" - end) : ");
 while ((ch=getche())!='.')
  {
   if (ch>='A' && ch<='z')
    printf("%c",ch);
  }
 getch();
}