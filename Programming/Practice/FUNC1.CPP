#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
float mul(float a,float b)
 {
  return (a*b);
 }
float add(float a,float b)
 {
  return (a+b);
 }
float sub(float a,float b)
 {
  return (a-b);
 }
float _div(float a,float b)
 {
  return (a/b);
 }
void main ()
 {
  char string[80];
  float numbers[20];
  char symbols[19];
  int n=0;
  float result;
  clrscr();
  puts("Enter the expression :");
  gets(string);
  numbers[0]=atof(string);
  for (int i=0; i<strlen(string); i++)
   {
    if (string[i]=='*' ||  string[i]=='/' || string[i]=='+' || string[i]=='-')
     {
      symbols[n]=string[i];
      numbers[n+1]=atof(string+i+1);
      n++;
     }
   }
  for (i=0; i<n; i++)
   {
    switch (symbols[i])
     {
      case '*' :
       numbers[i+1]=mul(numbers[i],numbers[i+1]);
       numbers[i]=0;
       symbols[i]=symbols[i-1];
       break;
      case '/' :
       numbers[i+1]=_div(numbers[i],numbers[i+1]);
       numbers[i]=0;
       symbols[i]=symbols[i-1];
       break;
     }
   }
  result=numbers[0];
  for (i=0; i<n; i++)
   {
    switch (symbols[i])
     {
      case '+' :
       result=add(numbers[i+1],result);
       break;
      case '-' :
       result=sub(result,numbers[i+1]);
       break;
     }
   }
  printf("The result is : %.3f",result);
  getch();
 }