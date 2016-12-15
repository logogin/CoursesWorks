%token LETTER
%left ','
%%
s:expr
expr:expr ',' expr1 ',' expr2
{if ($3!=$5)
puts("Incorrect words");
else
puts("Correct words");}
|expr1 ',' expr1
{if ($1!=$3)
puts("Incorrect words");
else
puts("Correct words");
}
expr1:expr1 LETTER
{$$=$1;$$-=$2;}
|LETTER
{$$=$1;}
expr2:LETTER expr2
{$$=$2;$$-=$1;}
|LETTER
{$$=$1;}

%%
#include "lex.yy.c"
int main()
{
return yyparse();
}
