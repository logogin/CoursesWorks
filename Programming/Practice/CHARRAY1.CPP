#include <stdio.h>
#include <conio.h>
#include <string.h>

int number(char ch);

int number(char ch)
{
 if (ch>='0' && ch<='9')
  return int(ch-'0');
 else return -1;
}

void main()
{
 char string[80];
 int sum=0,negative=0,n=0,flag=0;
 clrscr();
 puts("Enter the string :");
 gets(string);
 for (int i=0; i<strlen(string); i++)
  {
   if (string[i]=='-' && number(string[i+1])>=0)
     negative=1;
   while (number(string[i])>=0 && i<strlen(string))
    {
     n=(n+number(string[i++]))*10;
     flag=1;
    }
   if (flag)

    if (negative)
     {
      sum-=n/10;
      negative=0;
      n=0;
      flag=0;
     }
    else
     {
      sum+=n/10;
      n=0;
      flag=0;
     }
  }
 printf("The sum of numbers is %d",sum);
 getch();
}