%token DIGIT
%left '.' ' '
%%
s:expr
expr:number '.' expr1 ' ' expr1
{if ($1>$5 && $3<=99)
printf("Correct numbers\n");
else
printf("Incorrect numbers\n");}
expr1:expr1 DIGIT
{$$*=10;
$$+=$2;}
|DIGIT
{$$=$1;}
number:number DIGIT
{$$+=$2;}
|DIGIT
{$$=$1;}
		
%%
#include "lex.yy.c"
main()
{
return yyparse();
}
