#include <stdio.h>
#include <conio.h>
void main ()
{
 unsigned char ch;
 char negative=0;
 int sum=0,number=0,digit;

 clrscr();
 puts("Enter the string (\".\" - end) :");
 while ((ch=getchar())!='.' && ch!='\n')
  {
   if (ch=='-')
     negative=1;
   negative++;
   digit=1000;
   number=0;
   while ((ch!='.' && ch>='0' && ch<='9'))
    {
     digit/=10;
     number+=(int(ch-'0'))*digit;

     ch=getchar();
    }
   if (negative==3)
    {
     number/=digit;
     sum-=number;
    }
   else
    {
     number/=digit;
     sum+=number;
    }   
  }
 printf("The sum of numbers in the string is %d",sum);
 getch();

}
