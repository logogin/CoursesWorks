%token NUM
%left ','
%%
s: expr {if ($$==-1)
	printf("Correct numbers\n");
	else printf("Incorrect numbers\n");};
expr:NUM ',' NUM
{if (!($1%3) && !($3%2))
	$$=-1;
	 else $$=0;};
%%
#include "lex.yy.c" 
int main()
{
return yyparse();
}
