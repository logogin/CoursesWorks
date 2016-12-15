#include <stdio.h>
#include <conio.h>
void main ()
{
 unsigned char ch,letters=0,numbers=0,char_counter=0;

 clrscr();
 puts("Enter the string (\"!\" - end ):");
 while ((ch=getch())!='!')
  {
   char_counter++;
   if (ch>='0' && ch<='9')
    numbers++;
   if ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
    letters++;
  }

 printf("Number of digits : %d\n",numbers);
 printf("Number of letters : %d\n",letters);
 printf("Number of symbols : %d",char_counter-letters-numbers);
 getch();
}