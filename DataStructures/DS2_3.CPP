#include "stack.h"
#include <string.h>
#include <conio.h>

const char operators[7]={'(',')','*','/','+','-','\x0'};
const char priority[7]={3,3,2,2,1,1,0};

int get_operator(char ch)
 {
  int i=0;
  while (ch!=operators[i]&&i<6)
   i++;
  if (ch!=operators[i]) return 0;
  else return (i+1);
 }

void main()
 {
   char inf[80];
   int element;
   int len;
   int result;
   STACK expresion;
   STACK prefix;

   clrscr();
   printf("Enter infix expresion : ");
   gets(inf);
   len=strlen(inf);
   init_stack(&expresion,len);
   init_stack(&prefix,len);
   push_stack(&prefix,'\x0');
   for (int i=len-1; i>=0; i--)
   {
      result=get_operator(inf[i]);
      if (!result)
       push_stack(&expresion,inf[i]);
      else
	   if (inf[i]=='(')
	   {
	    test_stack(&prefix,&element);
	    while (element!=')')
		{
	     pop_stack(&prefix,&element);
	     push_stack(&expresion,element);
	     test_stack(&prefix,&element);
		}
	    pop_stack(&prefix,&element);
	   }
	   else
	   {
	    test_stack(&prefix,&element);
	    while ((priority[result-1]<=priority[get_operator(element)-1])
			&&element!=')')
		{
	     pop_stack(&prefix,&element);
	     push_stack(&expresion,element);
	     test_stack(&prefix,&element);
		}
	    push_stack(&prefix,inf[i]);
	   }
   }
   test_stack(&prefix,&element);
   while (element!='\x0')
    {
     pop_stack(&prefix,&element);
     push_stack(&expresion,element);
     test_stack(&prefix,&element);
    }

   printf("\nPrefix expresion is : ");
   while (expresion.sp)
    {
     pop_stack(&expresion,&element);
     printf("%c",element);
    }
   delete_stack(&expresion);
   delete_stack(&prefix);
   getch();
 }