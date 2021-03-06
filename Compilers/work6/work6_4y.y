%{
int i=0;
int vals[2];
char vars[80][2];
int size=0;
int count=0;
%}
%union
{char str[80];
int intval;}
%token <intval> IF DIGIT LETTER OPERATOR
%left ' ' '(' ')' '='
%type <intval> value if_expr bool_expr
%type <str> name
%%
s:expr
expr:var ' ' var ' ' if_expr
{if ($5)
puts("TRUE");
else
puts("FALSE");}
var:name '=' value
{strcpy(vars[count],$1);vals[count]=$3;count++;}
name:name LETTER
{$$[size]=$2;size++;$$[size]='\x0';}
|name DIGIT
{$$[size]=$2;size++;$$[size]='\x0';}
|LETTER
{size=0;$$[size]=$1;size++;}
value:value DIGIT
{$$=$1*10+($2-0x30);}
|DIGIT
{$$=$1-0x30;}
if_expr:IF '(' bool_expr ')'
{$$=$3;}
bool_expr:value OPERATOR name
{
if (!strcmp($3,vars[i]))
 $$=-vals[i];
$$+=$1;
switch($2)
{
case 0: if ($$) $$=1; else $$=0; break;
case 1: if (!$$) $$=1; else $$=0; break;
}
}
|name OPERATOR value
{
for (i=0; i<2; i++)
if (!strcmp($1,vars[i]))
 $$=vals[i];
$$-=$3;
switch($2)
{
case 0: if ($$) $$=1; else $$=0;break;
case 1: if (!$$) $$=1; else $$=0;break;
}
}
|name OPERATOR name
{for (i=0; i<2; i++)
if (!strcmp($1,vars[i]))
 $$=vals[i];
for (i=0; i<2; i++)
if (!strcmp($3,vars[i]))
$$-=vals[i];
switch($2)
{
case 0: if ($$) $$=1; else $$=0; break;
case 1: if (!$$) $$=1; else $$=0; break;
}
}
%%
#include "lex.yy.c"
int main()
{
 return yyparse();
}
