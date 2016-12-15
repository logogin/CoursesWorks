#include <stdio.h>
#include <conio.h>
void main ()
{
 unsigned char ch;
 char negative;
 clrscr();
 puts ("Enter the syting : ");
 while ((ch=getchar())!='\n')
  {
   if (ch>='A' && ch<='Z')
    {
     negative=1;
     putchar(ch+('a'-'A'));
    }
   if (ch>='a' && ch<='z')
    {
     negative=1;
     putchar(ch-('a'-'A'));
    }
   if (ch=='-')
    {
     ch=getchar();
     negative=2;
    }
   if  (ch>='0' && ch<='9' )
    {
     if (negative==1)
      putchar('-');
     putchar(ch);
     negative++;
    }
  }
 getch();
}