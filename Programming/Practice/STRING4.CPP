#include <conio.h>
#include <stdio.h>
void main ()
{
 char flag=1;
 unsigned char ch;
 clrscr();
 puts("Enter the string : ");
 while ((ch=getchar())!='\n')
  {
   if (ch==' ' && flag<2)
    {
     flag++;
     printf(" ");
    }
   else
    if (ch!=' ')
   // {
      putchar(ch);
     // flag=1;
    // }

  }
 getch();
}