#include <stdio.h>
#include <conio.h>
#include <string.h>
int compare(char s1[80],char s2[80])
 {
  int i=0;
  while (s1[i]==s2[i])
   i++;
  return int(s2[i]-s1[i]);
 }

void main()
{
 typedef string[80];
 char words[20][80],p[80];
 int n;
 clrscr();
 printf("Enter the number of words : ");
 scanf("%d",&n);
 for (int i=0; i<n; i++)
  {
   printf("Enter the %d word : ",i+1);
   scanf("%s",&words[i]);
  }
 for (i=0; i<n-1; i++)
  for (int j=i+1; j<n; j++)
   if (compare(words[j],words[i])>0)
    {
     strcpy(p,words[i]);
     strcpy(words[i],words[j]);
     strcpy(words[j],p);
    }
 for (i=0; i<n; i++)
  puts(words[i]);
 getch();
}