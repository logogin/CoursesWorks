#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(char *s1,char *s2)
 {
  int i=0;
  while ((s1[i]==s2[i]) && (s1[i]!='\x0') && (s2[i]!='\x0'))
   i++;
  return (s1[i]-s2[i]);
 }
void main ()
 {
  char *words[100],*p;
  int n;
  clrscr();
  for (int i=0; i<20; i++)
   words[i]=(char *)malloc(100);
  printf("Enter number of words : ");
  scanf("%d",&n);
  for (i=0; i<n; i++)
   {
    printf("Enter the %d word : ",i+1);
    scanf("%s",words[i]);
   }
  for (i=0; i<n-1; i++)
   for (int j=i+1; j<n; j++)
    {
     if (compare(words[i],words[j])>0)
      {
       strcpy(p,words[i]);
       strcpy(words[i],words[j]);
       strcpy(words[j],p);
      }
    }
  puts("\nNew list is : ");
  for (i=0; i<n; i++)
   puts(words[i]);
  getch();
 }