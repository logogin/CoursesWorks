%token LETTER
%left ','
%%
s:expr
expr:expr1 ',' expr2
{if ($1!=$3)
 puts("Incorrect words");
else
 puts("Correct words");}
expr1:LETTER expr1
{$$=$2-$1;}
|LETTER
{$$=$1;}
expr2:expr2 LETTER
{$$=$1-$2;}
|LETTER
{$$=$1;}
%%
#include "lex.yy.c"
int main()
{
 return yyparse();
}
yyerror()
{ 
return puts("Sintax error");
}