#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
 char str1[80],str2[40];
 int number=0,count=0,j,i1;
 clrscr();
 puts("Enter the first string :");
 gets(str1);
 puts("Enter the second string :");
 gets(str2);
 strlwr(str1);
 strlwr(str2);
 for (int i=0; i<=strlen(str1)-strlen(str2); i++)
  {
   j=0;
   i1=i;
   while (str1[i1]==str2[j] && j<strlen(str2))
    {
     count++;
     i1++;
     j++;
    }
   if (count==strlen(str2))
    {
     number++;
  //   i--;
    }
   count=0;
  }
 printf("The number of strings is %d",number);
 getch();
}