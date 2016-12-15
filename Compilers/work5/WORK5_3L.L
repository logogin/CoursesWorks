%%
[0-9]+	{strcpy(yylval.str,yytext);return NUM;}
"+"		return yytext[0];
"-"		return yytext[0];
%%
