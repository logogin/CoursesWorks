%{
int index=0;
int i;int j;%}
%union{
char str[80];}
%token <str> STRING
%left ' '
%type <str> s expr
%%
s:expr
expr:STRING ' ' STRING
{
for (i=0; i<strlen($3); i++)
{
 j=0;
 while ($3[i]==$1[j]&&i<strlen($3))
 {
  i++;j++;
  }
if (j>index)
index=j;
}
if (index==strlen($1))
puts("Correct words");
else
printf("%c\n",$1[index]);
}
%%
#include "lex.yy.c"
int main()
{
 return yyparse();
}
yyerror ()
{
return puts("Sintax error");
}
