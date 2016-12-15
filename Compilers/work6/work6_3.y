%{
int i;
int while_flag=0;
int break_flag=0;
int continue_flag=0;
char while_str[]="while";
char break_str="break"
char continue_str="continue";
%}
%union
{
char str[80];
}
%token <str> STRIMG
%type <str> s expr
%%
s:expr
expr:STRING ' ' expr
{
while_flag=0;
break_flag=0;
continue_flag=0;
for (i=0; i<strlen($1); i++)
{
 if (strlen($1)==5&&while_str[i]==$1[i])
 while_flag++;
 if (strlen($1)==5&&break_str[i]==$1[i])
 break_flag++;
if (strlen($1)==8&&continue_str[i]==$1[i])
 continue_flag++;
}
if (while_flag>2)
printf("while");
if (break_flag>2)
printf("break");
if (continue_flag>4)
printf("continue");
if (while_flag<3&&break_flag<3&&continue_flag<5)
printf("%s",$1);
}
|STRING
%%
#include "lex.yy.c"
int main()
{
 return yyparse();
}