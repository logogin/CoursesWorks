%union{char str[80];}
%token <str> NUM
%type <str> s expr
%left '+' '-'
%%
s:expr
{printf("Result : %s\n",$$);}
expr:expr '-' expr
{strcpy($$,$1);
strcpy($$+strlen($$),$3);}
|expr '+' expr
{strcpy($$,$3);
strcpy($$+strlen($$),$1);}
|NUM
{strcpy($$,$1);}		
%%
#include "lex.yy.c"
main()
{
return yyparse();
}
