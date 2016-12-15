%token FOR WHILE DO SENTENCE
%left ';' '{' '}'
%%
s:expr
expr:for_expr
{printf("For loop found\n");}
|while_expr
{printf("While loop found\n");}
|do_expr
{printf("Do-While loop found\n");}
for_expr:FOR '{' SENTENCE ';' SENTENCE ';' '}'
while_expr:WHILE '{' SENTENCE ';' SENTENCE ';' '}'
do_expr:DO '{' SENTENCE ';' SENTENCE ';' '}' WHILE ';'	
%%
#include "lex.yy.c"
main()
{
return yyparse();
}
