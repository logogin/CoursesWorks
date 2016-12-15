#include <stdio.h>
#include <string.h>
#include <conio.h>

char sentence[80],word[40],copy[80];
void main()
 {
  char *b_word=" ";
  int n,i=0,blank=0;
  clrscr();
  puts("Enter the sentence :");
  gets(sentence);
  puts("Enter the word :");
  gets(word);
  printf("Enter position : ");
  scanf("%d",&n);
  do
  {
   if ((sentence[i])==' ')
    blank++;
    i++;
  }
  while (blank<n && i<strlen(sentence));
  strcat(b_word,word);

  if (i!=strlen(sentence))
   {
    strcpy(copy,sentence+i-1);
    sentence[i-1]='\0';
   }
  strcpy(sentence+strlen(sentence),b_word);
  strcpy(sentence+strlen(sentence),copy);
  puts(sentence);
  getch();
 }