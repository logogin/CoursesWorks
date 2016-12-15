%{
int while_count=0;
int i=0;
int break_count=0;
int continue_count=0;
char while_str[]="while";
char break_str[]="break";
char continue_str[]="continue";%}
%union{
char str[80];}
%token <str> STRING
%type <str> s expr
%left ' '
%%
s:expr
{puts("");}
expr:expr ' ' STRING
{if (strlen($3)!=5&&strlen($3)!=8)
printf("%s ",$3);
else
{
if (strlen($3)==5)
{
break_count=0;
while_count=0;
for (i=0; i<strlen($3); i++)
{
if ($3[i]==while_str[i])
while_count++;
if ($3[i]==break_str[i])
break_count++;
}
if (while_count>2)
printf("while ");
if (break_count>2)
printf("break ");
if (while_count<3&&break_count<3)
printf("%s ",$3);
}
else
{
continue_count=0;
for (i=0; i<strlen($3); i++)
{if ($3[i]==continue_str[i])
continue_count++;}
if (continue_count>4)
printf("continue ");
else
printf("%s ",$3);
}
}
}
|STRING
{
if (strlen($1)!=5&&strlen($1)!=8)
printf("%s ",$1);
else
{
if (strlen($1)==5)
{
break_count=0;
while_count=0;
for (i=0; i<strlen($1); i++)
{
if ($1[i]==while_str[i])
while_count++;
if ($1[i]==break_str[i])
break_count++;
}
if (while_count>2)
printf("while ");
if (break_count>2)
printf("break ");
if (while_count<3&&break_count<3)
printf("%s ",$1);
}
else
{
continue_count=0;
for (i=0; i<strlen($1); i++)
{if ($1[i]==continue_str[i])
continue_count++;}
if (continue_count>4)
printf("continue ");
else
printf("%s ",$1);
}
}
}
%%
#include "lex.yy.c"
int main()
{
 return yyparse();
}
